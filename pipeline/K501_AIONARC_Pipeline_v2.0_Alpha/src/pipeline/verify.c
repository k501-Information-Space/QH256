#define _POSIX_C_SOURCE 200809L
#include "k501_aionarc/object_record.h"
#include "k501_aionarc/history.h"
#include "qh256.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

static int read_file(const char*path,uint8_t**out,size_t*len){FILE*f=fopen(path,"rb");long n;uint8_t*p;if(!f)return -1;if(fseek(f,0,SEEK_END)!=0){fclose(f);return -1;}n=ftell(f);if(n<0){fclose(f);return -1;}if(fseek(f,0,SEEK_SET)!=0){fclose(f);return -1;}p=malloc(n>0 ? (size_t)n : 1u);if(!p){fclose(f);return -1;}if((size_t)n&&fread(p,1,(size_t)n,f)!=(size_t)n){free(p);fclose(f);return -1;}fclose(f);*out=p;*len=(size_t)n;return 0;}
static int frame(const uint8_t*b,size_t n,size_t*p,const uint8_t**r,size_t*rl){if(*p>n||4u>n-*p)return -1;uint32_t k=(uint32_t)b[*p]|((uint32_t)b[*p+1u]<<8u)|((uint32_t)b[*p+2u]<<16u)|((uint32_t)b[*p+3u]<<24u);*p+=4u;if((size_t)k>n-*p)return -1;*r=b+*p;*rl=(size_t)k;*p+=(size_t)k;return 0;}
int main(int argc,char**argv){uint8_t*rb=NULL,*hb=NULL;size_t rn=0u,hn=0u,rp=0u,hp=0u,count=0u;uint8_t prev[32]={0u};if(argc!=3){fprintf(stderr,"usage: %s records.bin history.bin\n",argv[0]);return 2;}if(read_file(argv[1],&rb,&rn)!=0||read_file(argv[2],&hb,&hn)!=0){perror("read");free(rb);free(hb);return 1;}while(rp<rn){const uint8_t*rec;size_t recn;const uint8_t*hst;size_t hsn;k501_object_record_t d;k501_history_entry_t h;qh256_t q;if(frame(rb,rn,&rp,&rec,&recn)!=0){free(rb);free(hb);return 1;}if(!k501_object_record_verify(rec,recn,&d)){puts("FAIL: object record verification");free(rb);free(hb);return 1;}if(frame(hb,hn,&hp,&hst,&hsn)!=0||!k501_history_decode(hst,hsn,&h)){puts("FAIL: history frame decode");free(rb);free(hb);return 1;}if(h.sequence!=count||memcmp(h.record_hash,d.record_hash,32u)!=0||memcmp(h.object_id,d.object_id,32u)!=0||memcmp(h.previous_chain_hash,prev,32u)!=0||!k501_history_verify(&h,rec,recn)){puts("FAIL: history linkage");free(rb);free(hb);return 1;}if(!qh256_deserialize(&q,h.qh_state)){puts("FAIL: QH256 state decode");free(rb);free(hb);return 1;}memcpy(prev,h.chain_hash,32u);count++;}if(rp!=rn||hp!=hn){puts("FAIL: trailing or count mismatch");free(rb);free(hb);return 1;}printf("PASS: reconstructed %zu records and history entries\n",count);free(rb);free(hb);return 0;}
