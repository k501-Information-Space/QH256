#ifndef QH256_H
#define QH256_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#define QH256_VERSION_MAJOR 2u
#define QH256_VERSION_MINOR 0u
#define QH256_BITS 256u
#define QH256_BYTES 32u
#define QH256_CELLS 128u
#define QH256_CELL_BITS 2u
#define QH256_PLANE_BITS 128u
#define QH256_PLANE_BYTES 16u
#define QH256_WORDS 2u
_Static_assert(sizeof(uint64_t) == 8u, "QH256 requires 64-bit uint64_t");
_Static_assert(QH256_CELLS * QH256_CELL_BITS == QH256_BITS, "dimension mismatch");
_Static_assert(QH256_BITS / 8u == QH256_BYTES, "byte dimension mismatch");
_Static_assert(QH256_PLANE_BITS / 8u == QH256_PLANE_BYTES, "plane dimension mismatch");
typedef enum { QH_UNKNOWN=0u, QH_FALSE=1u, QH_TRUE=2u, QH_GUARD=3u } qh_state_t;
typedef struct { uint64_t t[QH256_WORDS]; uint64_t f[QH256_WORDS]; } qh256_t;
qh256_t qh256_unknown(void);
qh256_t qh256_delta_unknown(void);
bool qh256_equal(const qh256_t *a, const qh256_t *b);
bool qh256_is_zero(const qh256_t *q);
size_t qh256_size_bytes(void);
qh_state_t qh_encode(bool positive, bool negative);
bool qh_has_true(qh_state_t s);
bool qh_has_false(qh_state_t s);
bool qh_state_valid(qh_state_t s);
bool qh256_get_cell(const qh256_t *q, size_t index, qh_state_t *out);
bool qh256_set_cell(qh256_t *q, size_t index, qh_state_t state);
qh256_t qh256_merge(qh256_t a, qh256_t b);
qh256_t qh256_not(qh256_t a);
qh256_t qh256_and(qh256_t a, qh256_t b);
qh256_t qh256_or(qh256_t a, qh256_t b);
bool qh256_leq_k(const qh256_t *a, const qh256_t *b);
bool qh256_leq_t(const qh256_t *a, const qh256_t *b);
bool qh_is_designated(qh_state_t s);
bool qh256_is_designated(const qh256_t *q);
bool qh256_serialize(const qh256_t *q, uint8_t out[QH256_BYTES]);
bool qh256_deserialize(qh256_t *out, const uint8_t in[QH256_BYTES]);
qh_state_t qh_cell_merge(qh_state_t a, qh_state_t b);
qh_state_t qh_cell_not(qh_state_t a);
qh_state_t qh_cell_and(qh_state_t a, qh_state_t b);
qh_state_t qh_cell_or(qh_state_t a, qh_state_t b);
bool qh_cell_leq_k(qh_state_t a, qh_state_t b);
bool qh_cell_leq_t(qh_state_t a, qh_state_t b);
qh256_t qh256_replay(const qh256_t *deltas, size_t count);
#endif
