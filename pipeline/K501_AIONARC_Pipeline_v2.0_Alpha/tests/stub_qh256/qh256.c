#include "qh256.h"
#include <string.h>
qh256_t qh256_unknown(void){qh256_t q={{0u,0u},{0u,0u}};return q;}
void qh256_set_cell(qh256_t*q,size_t i,qh_state_t s){size_t w=i/64u,b=i%64u;uint64_t m=1ULL<<b;q->t[w]&=~m;q->f[w]&=~m;if(s==QH_TRUE||s==QH_GUARD)q->t[w]|=m;if(s==QH_FALSE||s==QH_GUARD)q->f[w]|=m;}
bool qh256_serialize(const qh256_t*q,uint8_t out[32]){size_t i,j;for(i=0u;i<2u;i++){for(j=0u;j<8u;j++)out[i*8u+j]=(uint8_t)(q->t[i]>>(j*8u));for(j=0u;j<8u;j++)out[16u+i*8u+j]=(uint8_t)(q->f[i]>>(j*8u));}return true;}
bool qh256_deserialize(qh256_t*q,const uint8_t in[32]){size_t i,j;memset(q,0,sizeof(*q));for(i=0u;i<2u;i++){for(j=0u;j<8u;j++)q->t[i]|=((uint64_t)in[i*8u+j])<<(j*8u);for(j=0u;j<8u;j++)q->f[i]|=((uint64_t)in[16u+i*8u+j])<<(j*8u);}return true;}
bool qh256_equal(const qh256_t*a,const qh256_t*b){return memcmp(a,b,sizeof(*a))==0;}
