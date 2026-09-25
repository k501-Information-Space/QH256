#ifndef K501_AIONARC_HISTORY_H
#define K501_AIONARC_HISTORY_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "qh256.h"
#include "k501_aionarc/object_record.h"
#define K501_HISTORY_MAGIC "K501HST2A"
typedef struct {uint64_t sequence;uint8_t object_id[32];uint8_t record_hash[32];uint8_t qh_state[32];uint8_t previous_chain_hash[32];uint8_t chain_hash[32];} k501_history_entry_t;
bool k501_history_build(uint64_t seq,const k501_object_record_t*r,const qh256_t*state,const uint8_t prev[32],const uint8_t*record_bytes,size_t record_len,k501_history_entry_t*out);
bool k501_history_serialize(const k501_history_entry_t*r,uint8_t**out,size_t*out_len);
bool k501_history_decode(const uint8_t*buf,size_t len,k501_history_entry_t*out);
bool k501_history_verify(const k501_history_entry_t*r,const uint8_t*record_bytes,size_t record_len);
#endif
