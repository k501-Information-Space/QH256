#include "qh256.h"
static unsigned word_index(size_t i){return (unsigned)(i/64u);}
static uint64_t bit_mask(size_t i){return UINT64_C(1) << (i%64u);}
static bool valid(qh_state_t s){return s<=QH_GUARD;}
qh256_t qh256_unknown(void){qh256_t q={{0u,0u},{0u,0u}};return q;}
qh256_t qh256_delta_unknown(void){return qh256_unknown();}
bool qh256_equal(const qh256_t*a,const qh256_t*b){return a&&b&&a->t[0]==b->t[0]&&a->t[1]==b->t[1]&&a->f[0]==b->f[0]&&a->f[1]==b->f[1];}
bool qh256_is_zero(const qh256_t*q){return q&&q->t[0]==0u&&q->t[1]==0u&&q->f[0]==0u&&q->f[1]==0u;}
size_t qh256_size_bytes(void){return (size_t)QH256_BYTES;}
qh_state_t qh_encode(bool p,bool n){return (qh_state_t)(((unsigned)p<<1u)|(unsigned)n);}
bool qh_has_true(qh_state_t s){return valid(s)&&(s&2u)!=0u;}
bool qh_has_false(qh_state_t s){return valid(s)&&(s&1u)!=0u;}
bool qh_state_valid(qh_state_t s){return valid(s);}
bool qh256_get_cell(const qh256_t*q,size_t i,qh_state_t*out){unsigned w;uint64_t m;unsigned code;if(!q||!out||i>=QH256_CELLS)return false;w=word_index(i);m=bit_mask(i);code=((q->t[w]&m)?2u:0u)|((q->f[w]&m)?1u:0u);*out=(qh_state_t)code;return true;}
bool qh256_set_cell(qh256_t*q,size_t i,qh_state_t s){unsigned w;uint64_t m;if(!q||i>=QH256_CELLS||!valid(s))return false;w=word_index(i);m=bit_mask(i);q->t[w]&=~m;q->f[w]&=~m;if(qh_has_true(s))q->t[w]|=m;if(qh_has_false(s))q->f[w]|=m;return true;}
qh256_t qh256_merge(qh256_t a,qh256_t b){qh256_t r={{a.t[0]|b.t[0],a.t[1]|b.t[1]},{a.f[0]|b.f[0],a.f[1]|b.f[1]}};return r;}
qh256_t qh256_not(qh256_t a){qh256_t r={{a.f[0],a.f[1]},{a.t[0],a.t[1]}};return r;}
qh256_t qh256_and(qh256_t a,qh256_t b){qh256_t r={{a.t[0]&b.t[0],a.t[1]&b.t[1]},{a.f[0]|b.f[0],a.f[1]|b.f[1]}};return r;}
qh256_t qh256_or(qh256_t a,qh256_t b){qh256_t r={{a.t[0]|b.t[0],a.t[1]|b.t[1]},{a.f[0]&b.f[0],a.f[1]&b.f[1]}};return r;}
bool qh256_leq_k(const qh256_t*a,const qh256_t*b){if(!a||!b)return false;return (a->t[0]&~b->t[0])==0u&&(a->t[1]&~b->t[1])==0u&&(a->f[0]&~b->f[0])==0u&&(a->f[1]&~b->f[1])==0u;}
bool qh256_leq_t(const qh256_t*a,const qh256_t*b){if(!a||!b)return false;return (a->t[0]&~b->t[0])==0u&&(a->t[1]&~b->t[1])==0u&&((~a->f[0])&b->f[0])==0u&&((~a->f[1])&b->f[1])==0u;}
bool qh_is_designated(qh_state_t s){return s==QH_TRUE||s==QH_GUARD;}
bool qh256_is_designated(const qh256_t*q){return q&&(q->t[0]|q->t[1])!=0u;}
static void put_le64(uint8_t o[8],uint64_t x){o[0]=(uint8_t)x;o[1]=(uint8_t)(x>>8u);o[2]=(uint8_t)(x>>16u);o[3]=(uint8_t)(x>>24u);o[4]=(uint8_t)(x>>32u);o[5]=(uint8_t)(x>>40u);o[6]=(uint8_t)(x>>48u);o[7]=(uint8_t)(x>>56u);}
static uint64_t get_le64(const uint8_t i[8]){return (uint64_t)i[0]|((uint64_t)i[1]<<8u)|((uint64_t)i[2]<<16u)|((uint64_t)i[3]<<24u)|((uint64_t)i[4]<<32u)|((uint64_t)i[5]<<40u)|((uint64_t)i[6]<<48u)|((uint64_t)i[7]<<56u);}
bool qh256_serialize(const qh256_t*q,uint8_t out[QH256_BYTES]){if(!q||!out)return false;put_le64(&out[0],q->t[0]);put_le64(&out[8],q->t[1]);put_le64(&out[16],q->f[0]);put_le64(&out[24],q->f[1]);return true;}
bool qh256_deserialize(qh256_t*out,const uint8_t in[QH256_BYTES]){if(!out||!in)return false;out->t[0]=get_le64(&in[0]);out->t[1]=get_le64(&in[8]);out->f[0]=get_le64(&in[16]);out->f[1]=get_le64(&in[24]);return true;}
qh_state_t qh_cell_merge(qh_state_t a,qh_state_t b){if(!valid(a)||!valid(b))return QH_UNKNOWN;return qh_encode(qh_has_true(a)||qh_has_true(b),qh_has_false(a)||qh_has_false(b));}
qh_state_t qh_cell_not(qh_state_t a){if(!valid(a))return QH_UNKNOWN;return qh_encode(qh_has_false(a),qh_has_true(a));}
qh_state_t qh_cell_and(qh_state_t a,qh_state_t b){if(!valid(a)||!valid(b))return QH_UNKNOWN;return qh_encode(qh_has_true(a)&&qh_has_true(b),qh_has_false(a)||qh_has_false(b));}
qh_state_t qh_cell_or(qh_state_t a,qh_state_t b){if(!valid(a)||!valid(b))return QH_UNKNOWN;return qh_encode(qh_has_true(a)||qh_has_true(b),qh_has_false(a)&&qh_has_false(b));}
bool qh_cell_leq_k(qh_state_t a,qh_state_t b){if(!valid(a)||!valid(b))return false;return (!qh_has_true(a)||qh_has_true(b))&&(!qh_has_false(a)||qh_has_false(b));}
bool qh_cell_leq_t(qh_state_t a,qh_state_t b){if(!valid(a)||!valid(b))return false;return (!qh_has_true(a)||qh_has_true(b))&&(!qh_has_false(b)||qh_has_false(a));}
qh256_t qh256_replay(const qh256_t*d,size_t n){qh256_t q=qh256_unknown();size_t i;if(!d&&n!=0u)return q;for(i=0;i<n;++i)q=qh256_merge(q,d[i]);return q;}
