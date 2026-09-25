#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "qh256.h"
#include "k501_aionarc/object_record.h"
#include "k501_aionarc/sha256.h"

static int same(const uint8_t*a,const uint8_t*b,size_t n){return memcmp(a,b,n)==0;}
static int sha_selftest(void){static const uint8_t abc[]={'a','b','c'};static const uint8_t exp[32]={0xba,0x78,0x16,0xbf,0x8f,0x01,0xcf,0xea,0x41,0x41,0x40,0xde,0x5d,0xae,0x22,0x23,0xb0,0x03,0x61,0xa3,0x96,0x17,0x7a,0x9c,0xb4,0x10,0xff,0x61,0xf2,0x00,0x15,0xad};uint8_t got[32];k501_sha256_ctx_t c;k501_sha256_init(&c);k501_sha256_update(&c,abc,sizeof abc);k501_sha256_final(&c,got);return same(got,exp,32u)?0:1;}
int main(void){static const uint8_t exp[32]={0xef,0xcd,0xab,0x89,0x67,0x45,0x23,0x01,0x10,0x32,0x54,0x76,0x98,0xba,0xdc,0xfe,0x78,0x69,0x5a,0x4b,0x3c,0x2d,0x1e,0x0f,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};qh256_t q={{0u,0u},{0u,0u}},r={{0u,0u},{0u,0u}};uint8_t out[32];
    q.t[0]=UINT64_C(0x0123456789abcdef);q.t[1]=UINT64_C(0xfedcba9876543210);q.f[0]=UINT64_C(0x0f1e2d3c4b5a6978);q.f[1]=UINT64_C(0x8877665544332211);
    if(!qh256_serialize(&q,out)||!same(out,exp,32u)){puts("FAIL: QH256 v2.0 t9 exact bytes");return 1;}if(!qh256_deserialize(&r,out)||!qh256_equal(&q,&r)){puts("FAIL: QH256 roundtrip");return 1;}puts("PASS: QH256 v2.0 t9 exact bytes + roundtrip");
    if(sha_selftest()!=0){puts("FAIL: SHA-256 abc vector");return 1;}puts("PASS: SHA-256 abc vector");
    return 0;
}
