#ifndef QH256ENGINE_HPP_
#define QH256ENGINE_HPP_

#include <cstdint>
#include <array>
#include <cassert>
#include <utility>

enum class DR4 : uint8_t {
    Invalid = 0,
    False   = 1,
    True    = 2,
    Guard   = 3
};

struct Lane {
    uint8_t b0 : 1;
    uint8_t b1 : 1;
};

struct State256 {
    std::array<Lane, 128> lanes;
};

inline Lane encode(DR4 state) {
    uint8_t s = static_cast<uint8_t>(state);
    return {static_cast<uint8_t>(s & 1), static_cast<uint8_t>((s >> 1) & 1)};
}

inline DR4 decode(const Lane& lane) {
    return static_cast<DR4>((lane.b1 << 1) | lane.b0);
}

// ============================================================================
// v6: Semantically Safe Permutations on {F, T, G}
// Invalid (U) is absolute fixpoint, never created or modified
// ============================================================================

inline void apply_semantic_transform(uint8_t transform_id, Lane& lane_a, Lane& lane_b) {
    DR4 state_a = decode(lane_a);
    DR4 state_b = decode(lane_b);
    
    // ABSOLUTE GUARD: Invalid never participates, never created
    if (state_a == DR4::Invalid || state_b == DR4::Invalid) {
        return;
    }
    
    // Now both are in {F, T, G} - apply semantically safe permutations
    switch (transform_id % 6) {
        case 0: {
            // Swap: complete lane exchange
            std::swap(lane_a, lane_b);
            break;
        }
        
        case 1: {
            // Identity: no change
            break;
        }
        
        case 2: {
            // Cyclic shift left in {F, T, G} for lane A
            // F(1) -> T(2), T(2) -> G(3), G(3) -> F(1)
            if (state_a == DR4::Guard) {
                lane_a = encode(DR4::False);
            } else {
                lane_a = encode(static_cast<DR4>(static_cast<uint8_t>(state_a) + 1));
            }
            break;
        }
        
        case 3: {
            // Cyclic shift right in {F, T, G} for lane B
            // F(1) <- T(2) <- G(3) <- F(1)
            if (state_b == DR4::False) {
                lane_b = encode(DR4::Guard);
            } else {
                lane_b = encode(static_cast<DR4>(static_cast<uint8_t>(state_b) - 1));
            }
            break;
        }
        
        case 4: {
            // Conditional inversion: if b is True, toggle a's boolean (F<->T), Guard stays
            if (state_b == DR4::True) {
                if (state_a == DR4::False) {
                    lane_a = encode(DR4::True);
                } else if (state_a == DR4::True) {
                    lane_a = encode(DR4::False);
                }
                // Guard stays Guard
            }
            break;
        }
        
        case 5: {
            // Controlled Guard mutation: merge different states toward Guard
            // with collision resolution to preserve entropy
            if (state_a != state_b) {
                if (state_a != DR4::Guard && state_b != DR4::Guard) {
                    // Both valid but different: converge to Guard
                    lane_a = encode(DR4::Guard);
                } else if (state_a == DR4::Guard && state_b == DR4::Guard) {
                    // Guard collision: resolve via entropy recovery
                    lane_a = encode(DR4::False);
                    lane_b = encode(DR4::True);
                }
                // If one is Guard and other isn't, leave as is (Guard dominates)
            }
            break;
        }
    }
}

inline uint8_t transform_selector(uint32_t round, uint8_t pair_index) {
    return ((2 * round + 3 * pair_index) % 6);
}

inline uint8_t routing_shift(uint32_t round, uint8_t lane_index) {
    return ((45 * lane_index + 17 * round) & 0x7F);
}

inline void apply_local_phase(State256& state, uint32_t round) {
    // Process adjacent pairs: (0,1), (2,3), ..., (126,127)
    for (uint8_t i = 0; i < 127; i += 2) {
        uint8_t trans_id = transform_selector(round, i / 2);
        apply_semantic_transform(trans_id, state.lanes[i], state.lanes[i + 1]);
    }
    
    // Process wrapped pairs with offset for asymmetry
    for (uint8_t i = 1; i < 128; i += 2) {
        uint8_t neighbor = (i + 2) % 128;
        uint8_t trans_id = transform_selector(round, 64 + (i / 2));
        apply_semantic_transform(trans_id, state.lanes[i], state.lanes[neighbor]);
    }
}

inline void apply_routing_phase(State256& state, uint32_t round) {
    State256 next;
    for (uint8_t i = 0; i < 128; i++) {
        uint8_t source = routing_shift(round, i);
        next.lanes[i] = state.lanes[source];
    }
    state = next;
}

inline void qh_round(State256& state, uint32_t round) {
    apply_local_phase(state, round);
    apply_routing_phase(state, round);
}

inline void qh_rounds(State256& state, uint32_t num_rounds) {
    for (uint32_t r = 0; r < num_rounds; r++) {
        qh_round(state, r);
    }
}

inline uint32_t count_invalid(const State256& state) {
    uint32_t count = 0;
    for (const auto& lane : state.lanes) {
        if (decode(lane) == DR4::Invalid) count++;
    }
    return count;
}

inline uint32_t count_guard(const State256& state) {
    uint32_t count = 0;
    for (const auto& lane : state.lanes) {
        if (decode(lane) == DR4::Guard) count++;
    }
    return count;
}

inline uint32_t count_false(const State256& state) {
    uint32_t count = 0;
    for (const auto& lane : state.lanes) {
        if (decode(lane) == DR4::False) count++;
    }
    return count;
}

inline uint32_t count_true(const State256& state) {
    uint32_t count = 0;
    for (const auto& lane : state.lanes) {
        if (decode(lane) == DR4::True) count++;
    }
    return count;
}

inline void set_lane(State256& state, uint8_t index, DR4 value) {
    assert(index < 128);
    state.lanes[index] = encode(value);
}

inline DR4 get_lane(const State256& state, uint8_t index) {
    assert(index < 128);
    return decode(state.lanes[index]);
}

inline void set_all(State256& state, DR4 value) {
    for (auto& lane : state.lanes) {
        lane = encode(value);
    }
}

inline State256 make_test_state_single_invalid(uint8_t idx) {
    State256 state;
    set_all(state, DR4::False);
    set_lane(state, idx, DR4::Invalid);
    return state;
}

inline State256 make_test_state_uniform(DR4 value) {
    State256 state;
    set_all(state, value);
    return state;
}

#endif
