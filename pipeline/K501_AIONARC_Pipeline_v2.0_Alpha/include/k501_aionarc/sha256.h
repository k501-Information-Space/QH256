#ifndef K501_AIONARC_SHA256_H
#define K501_AIONARC_SHA256_H
#include <stddef.h>
#include <stdint.h>
#define K501_SHA256_DIGEST_SIZE 32u
typedef struct { uint32_t state[8]; uint64_t bitlen; uint8_t data[64]; size_t datalen; } k501_sha256_ctx_t;
void k501_sha256_init(k501_sha256_ctx_t *ctx);
void k501_sha256_update(k501_sha256_ctx_t *ctx, const uint8_t *data, size_t len);
void k501_sha256_final(k501_sha256_ctx_t *ctx, uint8_t digest[K501_SHA256_DIGEST_SIZE]);
#endif
