#include "qh256.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned tests_run = 0u;
static unsigned tests_failed = 0u;

#define TEST_ASSERT(condition, message) do { \
    ++tests_run; \
    if (!(condition)) { \
        ++tests_failed; \
        fprintf(stderr, "FAIL: %s:%d: %s\n", __FILE__, __LINE__, (message)); \
    } \
} while (0)

static const qh256_state_t ALL_STATES[4] = {
    QH256_UNKNOWN,
    QH256_FALSE,
    QH256_TRUE,
    QH256_GUARD
};

static unsigned expected_merge(unsigned a, unsigned b) {
    return (a | b) & 0x03u;
}

static void fill_pattern(qh256_t *q) {
    size_t i;
    qh256_init(q);
    for (i = 0; i < QH256_CELL_COUNT; ++i) {
        (void)qh256_set(q, i, ALL_STATES[i % 4u]);
    }
}

static void test_static_structure(void) {
    TEST_ASSERT(QH256_CELL_COUNT == 128, "cell count must be 128");
    TEST_ASSERT(QH256_BITS == 256, "bit count must be 256");
    TEST_ASSERT(QH256_BYTES == 32, "byte count must be 32");
    TEST_ASSERT(QH256_BITS_PER_CELL == 2, "bits per cell must be 2");
    TEST_ASSERT(QH256_CELLS_PER_BYTE == 4, "cells per byte must be 4");
    TEST_ASSERT(sizeof(qh256_t) == 32u, "sizeof(qh256_t) must be 32");
}

static void test_state_encoding(void) {
    TEST_ASSERT(QH256_UNKNOWN == 0u, "UNKNOWN must encode as 00");
    TEST_ASSERT(QH256_FALSE == 1u, "FALSE must encode as 01");
    TEST_ASSERT(QH256_TRUE == 2u, "TRUE must encode as 10");
    TEST_ASSERT(QH256_GUARD == 3u, "GUARD must encode as 11");
}

static void test_all_cells_all_states(void) {
    qh256_t q;
    size_t i;
    size_t s;

    for (s = 0; s < 4u; ++s) {
        qh256_init(&q);
        for (i = 0; i < QH256_CELL_COUNT; ++i) {
            TEST_ASSERT(qh256_set(&q, i, ALL_STATES[s]), "set must accept valid cell/state");
        }
        for (i = 0; i < QH256_CELL_COUNT; ++i) {
            qh256_state_t actual = QH256_GUARD;
            TEST_ASSERT(qh256_get(&q, i, &actual), "get must accept valid cell");
            TEST_ASSERT(actual == ALL_STATES[s], "read-back state must match written state");
        }
    }
}

static void test_boundaries(void) {
    qh256_t q;
    qh256_state_t state;

    qh256_init(&q);

    TEST_ASSERT(qh256_set(&q, 0u, QH256_FALSE), "cell 0 must be writable");
    TEST_ASSERT(qh256_set(&q, 127u, QH256_TRUE), "cell 127 must be writable");
    TEST_ASSERT(!qh256_set(&q, 128u, QH256_FALSE), "cell 128 must be rejected");
    TEST_ASSERT(!qh256_get(&q, 128u, &state), "cell 128 read must be rejected");

    TEST_ASSERT(qh256_get(&q, 0u, &state) && state == QH256_FALSE, "cell 0 must retain value");
    TEST_ASSERT(qh256_get(&q, 127u, &state) && state == QH256_TRUE, "cell 127 must retain value");
}

static void test_byte_packing(void) {
    qh256_t q;
    uint8_t bytes[QH256_BYTES];

    qh256_init(&q);
    (void)qh256_set(&q, 0u, QH256_UNKNOWN);
    (void)qh256_set(&q, 1u, QH256_FALSE);
    (void)qh256_set(&q, 2u, QH256_TRUE);
    (void)qh256_set(&q, 3u, QH256_GUARD);
    qh256_to_bytes(&q, bytes);

    /* cell order within first byte: 00 01 10 11 -> binary 11 10 01 00 = 0xE4 */
    TEST_ASSERT(bytes[0] == 0xE4u, "first packed byte must be 0xE4");

    qh256_init(&q);
    (void)qh256_set(&q, 124u, QH256_FALSE);
    (void)qh256_set(&q, 125u, QH256_TRUE);
    (void)qh256_set(&q, 126u, QH256_GUARD);
    (void)qh256_set(&q, 127u, QH256_UNKNOWN);
    qh256_to_bytes(&q, bytes);
    TEST_ASSERT(bytes[31] == 0x39u, "last packed byte must be 0x39");
}

static void test_roundtrip_bytes(void) {
    qh256_t a;
    qh256_t b;
    uint8_t bytes[QH256_BYTES];

    fill_pattern(&a);
    qh256_to_bytes(&a, bytes);
    qh256_init(&b);
    TEST_ASSERT(qh256_from_bytes(&b, bytes), "from_bytes must succeed");
    TEST_ASSERT(qh256_equal(&a, &b), "byte roundtrip must be identity");
}

static void test_bitstring_roundtrip(void) {
    qh256_t a;
    qh256_t b;
    char bits[QH256_BITSTRING_LEN];
    size_t i;

    fill_pattern(&a);
    TEST_ASSERT(qh256_to_bitstring(&a, bits), "to_bitstring must succeed");
    TEST_ASSERT(strlen(bits) == QH256_BITS, "bitstring must contain 256 bits");
    TEST_ASSERT(qh256_from_bitstring(&b, bits), "from_bitstring must succeed");
    TEST_ASSERT(qh256_equal(&a, &b), "bitstring roundtrip must be identity");

    for (i = 0; i < strlen(bits); ++i) {
        TEST_ASSERT(bits[i] == '0' || bits[i] == '1', "bitstring may contain only 0 or 1");
    }
}

static void test_merge_truth_table(void) {
    size_t ai;
    size_t bi;

    for (ai = 0; ai < 4u; ++ai) {
        for (bi = 0; bi < 4u; ++bi) {
            qh256_state_t a = ALL_STATES[ai];
            qh256_state_t b = ALL_STATES[bi];
            qh256_state_t expected = (qh256_state_t)expected_merge((unsigned)ai, (unsigned)bi);
            qh256_state_t actual = qh256_merge_state(a, b);

            TEST_ASSERT(actual == expected, "single-cell MERGE_K oracle mismatch");
        }
    }
}

static void test_merge_commutativity(void) {
    size_t ai;
    size_t bi;

    for (ai = 0; ai < 4u; ++ai) {
        for (bi = 0; bi < 4u; ++bi) {
            qh256_state_t a = ALL_STATES[ai];
            qh256_state_t b = ALL_STATES[bi];
            TEST_ASSERT(qh256_merge_state(a, b) == qh256_merge_state(b, a),
                        "MERGE_K must be commutative");
        }
    }
}

static void test_merge_idempotence(void) {
    size_t i;
    for (i = 0; i < 4u; ++i) {
        qh256_state_t s = ALL_STATES[i];
        TEST_ASSERT(qh256_merge_state(s, s) == s, "MERGE_K must be idempotent");
    }
}

static void test_merge_associativity(void) {
    size_t ai;
    size_t bi;
    size_t ci;

    for (ai = 0; ai < 4u; ++ai) {
        for (bi = 0; bi < 4u; ++bi) {
            for (ci = 0; ci < 4u; ++ci) {
                qh256_state_t a = ALL_STATES[ai];
                qh256_state_t b = ALL_STATES[bi];
                qh256_state_t c = ALL_STATES[ci];
                qh256_state_t lhs = qh256_merge_state(qh256_merge_state(a, b), c);
                qh256_state_t rhs = qh256_merge_state(a, qh256_merge_state(b, c));
                TEST_ASSERT(lhs == rhs, "MERGE_K must be associative");
            }
        }
    }
}

static void test_merge_full_qh256(void) {
    qh256_t a;
    qh256_t b;
    qh256_t out;
    qh256_t expected;
    size_t i;

    qh256_init(&a);
    qh256_init(&b);
    qh256_init(&expected);

    for (i = 0; i < QH256_CELL_COUNT; ++i) {
        qh256_state_t sa = ALL_STATES[(i * 3u) % 4u];
        qh256_state_t sb = ALL_STATES[(i * 5u + 1u) % 4u];
        qh256_state_t se = qh256_merge_state(sa, sb);
        (void)qh256_set(&a, i, sa);
        (void)qh256_set(&b, i, sb);
        (void)qh256_set(&expected, i, se);
    }

    qh256_merge(&out, &a, &b);
    TEST_ASSERT(qh256_equal(&out, &expected), "full 128-cell merge must match cell oracle");

    qh256_merge(&out, &b, &a);
    TEST_ASSERT(qh256_equal(&out, &expected), "full 128-cell merge must be commutative");

    qh256_merge(&out, &a, &a);
    TEST_ASSERT(qh256_equal(&out, &a), "full 128-cell merge must be idempotent");
}

static void test_state_counts(void) {
    qh256_t q;
    qh256_init(&q);

    for (size_t i = 0; i < QH256_CELL_COUNT; ++i) {
        (void)qh256_set(&q, i, ALL_STATES[i % 4u]);
    }

    TEST_ASSERT(qh256_count_state(&q, QH256_UNKNOWN) == 32u, "UNKNOWN count must be 32");
    TEST_ASSERT(qh256_count_state(&q, QH256_FALSE) == 32u, "FALSE count must be 32");
    TEST_ASSERT(qh256_count_state(&q, QH256_TRUE) == 32u, "TRUE count must be 32");
    TEST_ASSERT(qh256_count_state(&q, QH256_GUARD) == 32u, "GUARD count must be 32");
}

static void test_invalid_inputs(void) {
    qh256_t q;
    qh256_state_t state;
    char bits[QH256_BITSTRING_LEN];

    qh256_init(&q);

    TEST_ASSERT(!qh256_set(NULL, 0u, QH256_UNKNOWN), "NULL set target must be rejected");
    TEST_ASSERT(!qh256_get(NULL, 0u, &state), "NULL get source must be rejected");
    TEST_ASSERT(!qh256_get(&q, 0u, NULL), "NULL get output must be rejected");
    TEST_ASSERT(!qh256_set(&q, 0u, (qh256_state_t)4u), "invalid state must be rejected");

    memset(bits, '0', QH256_BITS);
    bits[QH256_BITS] = 'X';
    TEST_ASSERT(!qh256_from_bitstring(&q, bits), "invalid bitstring terminator must be rejected");

    memset(bits, '0', QH256_BITS);
    bits[10] = '2';
    bits[QH256_BITS] = '\0';
    TEST_ASSERT(!qh256_from_bitstring(&q, bits), "invalid bitstring character must be rejected");
}

static void run_all_tests(void) {
    test_static_structure();
    test_state_encoding();
    test_all_cells_all_states();
    test_boundaries();
    test_byte_packing();
    test_roundtrip_bytes();
    test_bitstring_roundtrip();
    test_merge_truth_table();
    test_merge_commutativity();
    test_merge_idempotence();
    test_merge_associativity();
    test_merge_full_qh256();
    test_state_counts();
    test_invalid_inputs();
}

int main(void) {
    run_all_tests();

    printf("QH256 Validation\n");
    printf("Tests run:    %u\n", tests_run);
    printf("Tests failed: %u\n", tests_failed);
    printf("Result:       %s\n", tests_failed == 0u ? "PASS" : "FAIL");

    return tests_failed == 0u ? EXIT_SUCCESS : EXIT_FAILURE;
}
