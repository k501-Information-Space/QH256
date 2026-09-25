#ifndef K501_AIONARC_BYTES_H
#define K501_AIONARC_BYTES_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
typedef struct { uint8_t *data; size_t len; size_t cap; } k501_buf_t;
void k501_buf_free(k501_buf_t*b);
bool k501_buf_put(k501_buf_t*b,const uint8_t*p,size_t n);
bool k501_buf_put_u8(k501_buf_t*b,uint8_t v);
bool k501_buf_put_u32le(k501_buf_t*b,uint32_t v);
bool k501_buf_put_u64le(k501_buf_t*b,uint64_t v);
bool k501_buf_put_i64le(k501_buf_t*b,int64_t v);
bool k501_buf_put_i32le(k501_buf_t*b,int32_t v);
bool k501_buf_put_len_bytes(k501_buf_t*b,const uint8_t*p,size_t n);
bool k501_get_u8(const uint8_t*buf,size_t len,size_t*pos,uint8_t*out);
bool k501_get_u32le(const uint8_t*buf,size_t len,size_t*pos,uint32_t*out);
bool k501_get_u64le(const uint8_t*buf,size_t len,size_t*pos,uint64_t*out);
bool k501_get_i64le(const uint8_t*buf,size_t len,size_t*pos,int64_t*out);
bool k501_get_i32le(const uint8_t*buf,size_t len,size_t*pos,int32_t*out);
bool k501_get_bytes_view(const uint8_t*buf,size_t len,size_t*pos,const uint8_t**out,size_t*out_len);
#endif
