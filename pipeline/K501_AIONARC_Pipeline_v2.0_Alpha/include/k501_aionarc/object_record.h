#ifndef K501_AIONARC_OBJECT_RECORD_H
#define K501_AIONARC_OBJECT_RECORD_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#define K501_BOR_SCHEMA "K501-OBJECT-2.0-ALPHA"
#define K501_OID_DOMAIN "K501-OID-V2A\0"
typedef enum {K501_OBJ_REGULAR_FILE=1u,K501_OBJ_DIRECTORY=2u,K501_OBJ_SYMLINK=3u,K501_OBJ_OTHER=4u} k501_object_type_t;
typedef struct {const uint8_t*schema;size_t schema_len;uint8_t object_id[32];const uint8_t*root_id;size_t root_id_len;const uint8_t*path;size_t path_len;k501_object_type_t object_type;bool size_present;uint64_t size_bytes;bool content_present;uint8_t content_sha256[32];int64_t mtime_sec;int32_t mtime_nsec;uint32_t mode;bool readable;uint8_t record_hash[32];} k501_object_record_t;
bool k501_object_record_compute_object_id(const k501_object_record_t*r,uint8_t out[32]);
bool k501_object_record_serialize_prefix(const k501_object_record_t*r,uint8_t**out,size_t*out_len);
bool k501_object_record_serialize(const k501_object_record_t*r,uint8_t**out,size_t*out_len);
bool k501_object_record_decode(const uint8_t*buf,size_t len,k501_object_record_t*out,size_t*consumed);
bool k501_object_record_verify(const uint8_t*buf,size_t len,k501_object_record_t*decoded);
#endif
