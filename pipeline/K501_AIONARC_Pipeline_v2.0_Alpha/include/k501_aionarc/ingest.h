#ifndef K501_AIONARC_INGEST_H
#define K501_AIONARC_INGEST_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "k501_aionarc/object_record.h"
typedef struct {uint8_t*path;size_t path_len;k501_object_type_t object_type;bool size_present;uint64_t size_bytes;bool content_present;uint8_t content_sha256[32];int64_t mtime_sec;int32_t mtime_nsec;uint32_t mode;bool readable;} k501_observation_t;
typedef struct {k501_observation_t*items;size_t len;size_t cap;} k501_observation_set_t;
void k501_observation_set_free(k501_observation_set_t*s);
bool k501_ingest_run(const uint8_t*root,size_t root_len,k501_observation_set_t*out);
#endif
