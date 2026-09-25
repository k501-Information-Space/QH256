#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "qh256.h"
_Static_assert(QH256_BITS==256u,"QH256_BITS drift");
_Static_assert(QH256_BYTES==32u,"QH256_BYTES drift");
_Static_assert(QH256_CELLS==128u,"QH256_CELLS drift");
int main(void){static const uint8_t exp[32]={0xef,0xcd,0xab,0x89,0x67,0x45,0x23,0x01,0x10,0x32,0x54,0x76,0x98,0xba,0xdc,0xfe,0x78,0x69,0x5a,0x4b,0x3c,0x2d,0x1e,0x0f,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};qh256_t q={{0u,0u},{0u,0u}},r={{0u,0u},{0u,0u}};uint8_t b[32];q.t[0]=UINT64_C(0x0123456789abcdef);q.t[1]=UINT64_C(0xfedcba9876543210);q.f[0]=UINT64_C(0x0f1e2d3c4b5a6978);q.f[1]=UINT64_C(0x8877665544332211);puts("V02-2C DIRECT-CORE-BINDING TEST");if(!qh256_serialize(&q,b)){puts("FAIL: serialize returned false");return 1;}if(memcmp(b,exp,32u)!=0){puts("FAIL: canonical t9 byte vector mismatch");return 1;}puts("PASS: canonical t9 byte vector exact match");if(!qh256_deserialize(&r,b)){puts("FAIL: deserialize returned false");return 1;}if(!qh256_equal(&q,&r)){puts("FAIL: roundtrip equality");return 1;}puts("PASS: qh256_equal() roundtrip");puts("RESULT: PASS");return 0;}
