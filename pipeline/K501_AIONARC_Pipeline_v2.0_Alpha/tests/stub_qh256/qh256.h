#ifndef QH256_H
#define QH256_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#define QH256_BITS 256u
#define QH256_BYTES 32u
#define QH256_CELLS 128u
typedef enum {QH_UNKNOWN=0u,QH_FALSE=1u,QH_TRUE=2u,QH_GUARD=3u} qh_state_t;
typedef struct {uint64_t t[2];uint64_t f[2];} qh256_t;
qh256_t qh256_unknown(void); void qh256_set_cell(qh256_t*,size_t,qh_state_t); bool qh256_serialize(const qh256_t*,uint8_t out[32]); bool qh256_deserialize(qh256_t*,const uint8_t in[32]); bool qh256_equal(const qh256_t*,const qh256_t*);
#endif
