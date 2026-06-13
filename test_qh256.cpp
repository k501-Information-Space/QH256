#include "QH256Engine.hpp"
#include <iostream>
#include <iomanip>

int test_count = 0;
int test_passed = 0;

void test_result(const char* name, bool passed) {
    test_count++;
    if (passed) {
        test_passed++;
        std::cout << "  [PASS] " << name << "\n";
    } else {
        std::cout << "  [FAIL] " << name << "\n";
    }
}

void test_encode_decode() {
    std::cout << "\n[TEST] Encode/Decode correctness\n";
    bool all_ok = true;
    for (int i = 0; i < 4; i++) {
        DR4 original = static_cast<DR4>(i);
        Lane encoded = encode(original);
        DR4 decoded = decode(encoded);
        if (decoded != original) {
            all_ok = false;
            break;
        }
    }
    test_result("All DR4 states encode/decode correctly", all_ok);
}

void test_invalid_fixity() {
    std::cout << "\n[TEST] Invalid Fixity: U is absolute fixpoint\n";
    
    State256 state;
    set_all(state, DR4::False);
    set_lane(state, 0, DR4::Invalid);
    set_lane(state, 64, DR4::Invalid);
    
    uint32_t invalid_before = count_invalid(state);
    
    qh_rounds(state, 32);
    
    uint32_t invalid_after = count_invalid(state);
    
    std::cout << "    Invalid count before: " << invalid_before << "\n";
    std::cout << "    Invalid count after:  " << invalid_after << "\n";
    
    test_result("Invalid count unchanged (absolute fixity)", 
                invalid_before == invalid_after && invalid_before == 2);
}

void test_guard_invariance() {
    std::cout << "\n[TEST] Guard Invariance: G lanes dominate\n";
    
    State256 state;
    set_all(state, DR4::False);
    
    // Set guards at regular intervals
    for (uint8_t i = 0; i < 128; i += 8) {
        set_lane(state, i, DR4::Guard);
    }
    
    uint32_t guard_before = count_guard(state);
    
    qh_rounds(state, 32);
    
    uint32_t guard_after = count_guard(state);
    
    std::cout << "    Guard lanes before: " << guard_before << "\n";
    std::cout << "    Guard lanes after:  " << guard_after << "\n";
    
    // Guards should increase or stay, never decrease (they dominate)
    bool preserved = (guard_after >= guard_before);
    test_result("Guard lanes increase or stay (dominance)", preserved);
}

void test_diffusion() {
    std::cout << "\n[TEST] Diffusion: Entropy spreads across state\n";
    
    // Test 1: Entropy conservation
    State256 state;
    set_all(state, DR4::False);
    
    uint32_t entropy_before = count_false(state) + count_true(state) + count_guard(state);
    qh_rounds(state, 32);
    uint32_t entropy_after = count_false(state) + count_true(state) + count_guard(state);
    
    bool entropy_conserved = (entropy_before == entropy_after);
    std::cout << "    Entropy before: " << entropy_before << ", after: " << entropy_after << "\n";
    
    // Test 2: Distribution evolution (not all lanes same state)
    State256 state2;
    set_all(state2, DR4::False);
    set_lane(state2, 0, DR4::True);
    set_lane(state2, 64, DR4::Guard);
    
    qh_rounds(state2, 32);
    
    uint32_t f = count_false(state2);
    uint32_t t = count_true(state2);
    uint32_t g = count_guard(state2);
    
    std::cout << "    After 32 rounds: " << f << " False, " << t << " True, " << g << " Guard\n";
    
    // If diffusion works, should have mixed distribution
    bool diffused = (f > 0 && t > 0 && g > 0 && f < 100 && t < 100);
    
    test_result("Entropy and distribution (valid mixing)", entropy_conserved && diffused);
}

void test_state_mixing() {
    std::cout << "\n[TEST] State Mixing: F and T become balanced\n";
    
    State256 state;
    set_all(state, DR4::False);
    
    // Mark every other lane as True
    for (uint8_t i = 0; i < 128; i += 2) {
        set_lane(state, i, DR4::True);
    }
    
    std::cout << "    Initial: " << count_false(state) << " False, " 
              << count_true(state) << " True\n";
    
    qh_rounds(state, 32);
    
    uint32_t f_count = count_false(state);
    uint32_t t_count = count_true(state);
    
    std::cout << "    Final:   " << f_count << " False, " << t_count << " True\n";
    
    // Should mix: both should be in reasonable range (not still 64-64)
    bool mixed = (f_count > 10 && f_count < 118) && (t_count > 10 && t_count < 118);
    test_result("States mix well (not isolated)", mixed);
}

void test_no_invalid_creation() {
    std::cout << "\n[TEST] Invalid Creation Safety: No new U states created\n";
    
    State256 state = make_test_state_uniform(DR4::False);
    
    uint32_t invalid_before = count_invalid(state);
    
    qh_rounds(state, 32);
    
    uint32_t invalid_after = count_invalid(state);
    
    std::cout << "    Invalid count: " << invalid_before << " -> " << invalid_after << "\n";
    
    test_result("No new Invalid created", invalid_after == invalid_before);
}

int main() {
    std::cout << "====== QH256 Unit Tests (v6 - Semantically Safe) ======\n";
    
    test_encode_decode();
    test_no_invalid_creation();
    test_invalid_fixity();
    test_guard_invariance();
    test_state_mixing();
    test_diffusion();
    
    std::cout << "\n====== Summary ======\n";
    std::cout << "Tests passed: " << test_passed << "/" << test_count << "\n";
    
    if (test_passed == test_count) {
        std::cout << "✓ All tests passed!\n";
        return 0;
    } else {
        std::cout << "✗ Some tests failed.\n";
        return 1;
    }
}
