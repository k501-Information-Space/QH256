#include "k501_aionarc/bytes.h"
#include <stdlib.h>
#include <string.h>
void k501_buf_free(k501_buf_t*b){if(b){free(b->data);b->data=NULL;b->len=0u;b->cap=0u;}}
static bool reserve(k501_buf_t*b,size_t add){size_t need,cap;uint8_t*p;if(!b||add>SIZE_MAX-b->len)return false;need=b->len+add;if(need<=b->cap)return true;cap=b->cap?b->cap:256u;while(cap<need){if(cap>SIZE_MAX/2u){cap=need;break;}cap*=2u;}p=(uint8_t*)realloc(b->data,cap);if(!p)return false;b->data=p;b->cap=cap;return true;}
bool k501_buf_put(k501_buf_t*b,const uint8_t*p,size_t n){if(!reserve(b,n))return false;if(n)memcpy(b->data+b->len,p,n);b->len+=n;return true;}
bool k501_buf_put_u8(k501_buf_t*b,uint8_t v){return k501_buf_put(b,&v,1u);}
bool k501_buf_put_u32le(k501_buf_t*b,uint32_t v){uint8_t p[4]={(uint8_t)v,(uint8_t)(v>>8u),(uint8_t)(v>>16u),(uint8_t)(v>>24u)};return k501_buf_put(b,p,4u);}
bool k501_buf_put_u64le(k501_buf_t*b,uint64_t v){uint8_t p[8];size_t i;for(i=0u;i<8u;i++)p[i]=(uint8_t)(v>>(i*8u));return k501_buf_put(b,p,8u);}
bool k501_buf_put_i64le(k501_buf_t*b,int64_t v){return k501_buf_put_u64le(b,(uint64_t)v);}
bool k501_buf_put_i32le(k501_buf_t*b,int32_t v){return k501_buf_put_u32le(b,(uint32_t)v);}
bool k501_buf_put_len_bytes(k501_buf_t*b,const uint8_t*p,size_t n){return n<=UINT32_MAX&&k501_buf_put_u32le(b,(uint32_t)n)&&k501_buf_put(b,p,n);}
static bool take(const uint8_t*b,size_t n,size_t*pos,size_t k,const uint8_t**out){if(!b||!pos||!out||*pos>n||k>n-*pos)return false;*out=b+*pos;*pos+=k;return true;}
bool k501_get_u8(const uint8_t*b,size_t n,size_t*pos,uint8_t*out){const uint8_t*p;if(!out||!take(b,n,pos,1u,&p))return false;*out=p[0];return true;}
bool k501_get_u32le(const uint8_t*b,size_t n,size_t*pos,uint32_t*out){const uint8_t*p;if(!out||!take(b,n,pos,4u,&p))return false;*out=(uint32_t)p[0]|((uint32_t)p[1]<<8u)|((uint32_t)p[2]<<16u)|((uint32_t)p[3]<<24u);return true;}
bool k501_get_u64le(const uint8_t*b,size_t n,size_t*pos,uint64_t*out){const uint8_t*p;size_t i;uint64_t v=0u;if(!out||!take(b,n,pos,8u,&p))return false;for(i=0u;i<8u;i++)v|=((uint64_t)p[i])<<(i*8u);*out=v;return true;}
bool k501_get_i64le(const uint8_t*b,size_t n,size_t*pos,int64_t*out){uint64_t u;if(!out||!k501_get_u64le(b,n,pos,&u))return false;*out=(int64_t)u;return true;}
bool k501_get_i32le(const uint8_t*b,size_t n,size_t*pos,int32_t*out){uint32_t u;if(!out||!k501_get_u32le(b,n,pos,&u))return false;*out=(int32_t)u;return true;}
bool k501_get_bytes_view(const uint8_t*b,size_t n,size_t*pos,const uint8_t**out,size_t*out_len){uint32_t k;if(!out||!out_len||!k501_get_u32le(b,n,pos,&k))return false;return take(b,n,pos,(size_t)k,out)?(*out_len=(size_t)k,true):false;}
