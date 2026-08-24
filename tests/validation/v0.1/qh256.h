#ifndef QH256_H
#define QH256_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * QH256 canonical structure:
 *   128 cells x 2 bits = 256 bits = 32 bytes.
 *
 * Canonical cell encoding:
 *   00 = UNKNOWN
 *   01 = FALSE
 *   10 = TRUE
 *   11 = GUARD
 *
 * Canonical packing:
 *   cell 0 -> bits 1:0 of byte 0
 *   cell 1 -> bits 3:2 of byte 0
 *   cell 2 -> bits 5:4 of byte 0
 *   cell 3 -> bits 7:6 of byte 0
 *   cell 4 -> bits 1:0 of byte 1
 *   ...
 *   cell 127 -> bits 7:6 of byte 31
 */

enum {
    QH256_CELL_COUNT = 128,
    QH256_BITS = 256,
    QH256_BYTES = 32,
    QH256_BITS_PER_CELL = 2,
    QH256_CELLS_PER_BYTE = 4
};

typedef enum {
    QH256_UNKNOWN = 0u, /* 00 */
    QH256_FALSE   = 1u, /* 01 */
    QH256_TRUE    = 2u, /* 10 */
    QH256_GUARD   = 3u  /* 11 */
} qh256_state_t;

typedef struct {
    uint8_t bytes[QH256_BYTES];
} qh256_t;

/* Compile-time invariants. */
_Static_assert(QH256_CELL_COUNT == 128, "QH256 must contain 128 cells");
_Static_assert(QH256_BITS == 256, "QH256 must contain 256 bits");
_Static_assert(QH256_BYTES == 32, "QH256 must contain 32 bytes");
_Static_assert(QH256_BITS_PER_CELL == 2, "QH256 cells must contain 2 bits");
_Static_assert(QH256_CELLS_PER_BYTE == 4, "QH256 must pack 4 cells per byte");
_Static_assert(sizeof(qh256_t) == QH256_BYTES, "qh256_t must be exactly 32 bytes");

/* Object lifecycle. */
void qh256_init(qh256_t *q);
void qh256_zero(qh256_t *q);

/* Validation helpers. */
int qh256_valid_cell_index(size_t cell_index);
int qh256_valid_state(qh256_state_t state);

/* Cell access. */
int qh256_set(qh256_t *q, size_t cell_index, qh256_state_t state);
int qh256_get(const qh256_t *q, size_t cell_index, qh256_state_t *out_state);

/* Equality and deterministic representations. */
int qh256_equal(const qh256_t *a, const qh256_t *b);
void qh256_to_bytes(const qh256_t *q, uint8_t out[QH256_BYTES]);
int qh256_from_bytes(qh256_t *q, const uint8_t in[QH256_BYTES]);

/* Fixed-size canonical bit-string representation: 256 chars + '\0'. */
#define QH256_BITSTRING_LEN (QH256_BITS + 1u)
int qh256_to_bitstring(const qh256_t *q, char out[QH256_BITSTRING_LEN]);
int qh256_from_bitstring(qh256_t *q, const char *bits);

/* Merge operation defined as bitwise OR of the two-bit cell encodings. */
qh256_state_t qh256_merge_state(qh256_state_t a, qh256_state_t b);
void qh256_merge(qh256_t *out, const qh256_t *a, const qh256_t *b);

/* Useful structural queries. */
size_t qh256_count_state(const qh256_t *q, qh256_state_t state);

#ifdef __cplusplus
}
#endif

#endif /* QH256_H */
