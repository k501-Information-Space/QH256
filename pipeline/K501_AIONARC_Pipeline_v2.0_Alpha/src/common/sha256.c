#include "k501_aionarc/sha256.h"
#include <string.h>
static uint32_t r(uint32_t x,uint32_t n){return (x>>n)|(x<<(32u-n));}
static uint32_t Ch(uint32_t x,uint32_t y,uint32_t z){return (x&y)^(~x&z);}
static uint32_t Maj(uint32_t x,uint32_t y,uint32_t z){return (x&y)^(x&z)^(y&z);}
static uint32_t B0(uint32_t x){return r(x,2u)^r(x,13u)^r(x,22u);}
static uint32_t B1(uint32_t x){return r(x,6u)^r(x,11u)^r(x,25u);}
static uint32_t S0(uint32_t x){return r(x,7u)^r(x,18u)^(x>>3u);}
static uint32_t S1(uint32_t x){return r(x,17u)^r(x,19u)^(x>>10u);}
static const uint32_t K[64]={0x428a2f98u,0x71374491u,0xb5c0fbcfu,0xe9b5dba5u,0x3956c25bu,0x59f111f1u,0x923f82a4u,0xab1c5ed5u,0xd807aa98u,0x12835b01u,0x243185beu,0x550c7dc3u,0x72be5d74u,0x80deb1feu,0x9bdc06a7u,0xc19bf174u,0xe49b69c1u,0xefbe4786u,0x0fc19dc6u,0x240ca1ccu,0x2de92c6fu,0x4a7484aau,0x5cb0a9dcu,0x76f988dau,0x983e5152u,0xa831c66du,0xb00327c8u,0xbf597fc7u,0xc6e00bf3u,0xd5a79147u,0x06ca6351u,0x14292967u,0x27b70a85u,0x2e1b2138u,0x4d2c6dfcu,0x53380d13u,0x650a7354u,0x766a0abbu,0x81c2c92eu,0x92722c85u,0xa2bfe8a1u,0xa81a664bu,0xc24b8b70u,0xc76c51a3u,0xd192e819u,0xd6990624u,0xf40e3585u,0x106aa070u,0x19a4c116u,0x1e376c08u,0x2748774cu,0x34b0bcb5u,0x391c0cb3u,0x4ed8aa4au,0x5b9cca4fu,0x682e6ff3u,0x748f82eeu,0x78a5636fu,0x84c87814u,0x8cc70208u,0x90befffau,0xa4506cebu,0xbef9a3f7u,0xc67178f2u};
static uint32_t be32(const uint8_t*p){return ((uint32_t)p[0]<<24u)|((uint32_t)p[1]<<16u)|((uint32_t)p[2]<<8u)|(uint32_t)p[3];}
static void putbe(uint8_t*p,uint32_t v){p[0]=(uint8_t)(v>>24u);p[1]=(uint8_t)(v>>16u);p[2]=(uint8_t)(v>>8u);p[3]=(uint8_t)v;}
static void tf(k501_sha256_ctx_t*c,const uint8_t d[64]){uint32_t w[64],a,b,cc,dv,e,f,g,h;size_t i;for(i=0u;i<16u;i++)w[i]=be32(d+i*4u);for(i=16u;i<64u;i++)w[i]=S1(w[i-2u])+w[i-7u]+S0(w[i-15u])+w[i-16u];a=c->state[0];b=c->state[1];cc=c->state[2];dv=c->state[3];e=c->state[4];f=c->state[5];g=c->state[6];h=c->state[7];for(i=0u;i<64u;i++){uint32_t t1=h+B1(e)+Ch(e,f,g)+K[i]+w[i],t2=B0(a)+Maj(a,b,cc);h=g;g=f;f=e;e=dv+t1;dv=cc;cc=b;b=a;a=t1+t2;}c->state[0]+=a;c->state[1]+=b;c->state[2]+=cc;c->state[3]+=dv;c->state[4]+=e;c->state[5]+=f;c->state[6]+=g;c->state[7]+=h;}
void k501_sha256_init(k501_sha256_ctx_t*c){c->state[0]=0x6a09e667u;c->state[1]=0xbb67ae85u;c->state[2]=0x3c6ef372u;c->state[3]=0xa54ff53au;c->state[4]=0x510e527fu;c->state[5]=0x9b05688cu;c->state[6]=0x1f83d9abu;c->state[7]=0x5be0cd19u;c->bitlen=0u;c->datalen=0u;}
void k501_sha256_update(k501_sha256_ctx_t*c,const uint8_t*d,size_t n){size_t i;for(i=0u;i<n;i++){c->data[c->datalen++]=d[i];if(c->datalen==64u){tf(c,c->data);c->bitlen+=512u;c->datalen=0u;}}}
void k501_sha256_final(k501_sha256_ctx_t*c,uint8_t out[32]){uint64_t bits=c->bitlen+(uint64_t)c->datalen*8u;size_t i=c->datalen;c->data[i++]=0x80u;while(i<56u)c->data[i++]=0u;if(c->datalen>=56u){while(i<64u)c->data[i++]=0u;tf(c,c->data);memset(c->data,0,56u);}for(i=0u;i<8u;i++)c->data[63u-i]=(uint8_t)(bits>>(i*8u));tf(c,c->data);for(i=0u;i<8u;i++)putbe(out+i*4u,c->state[i]);}
