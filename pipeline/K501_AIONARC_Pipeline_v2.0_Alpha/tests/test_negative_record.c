#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "k501_aionarc/object_record.h"

static void make_record(k501_object_record_t *r,const uint8_t **schema,const uint8_t **root,const uint8_t **path){
    static const uint8_t s[]=K501_BOR_SCHEMA,ro[]="ROOT_TEST_V2_ALPHA",pa[]={'a','b',0xffu};
    memset(r,0,sizeof *r);*schema=s;*root=ro;*path=pa;r->schema=s;r->schema_len=sizeof(s)-1u;r->root_id=ro;r->root_id_len=sizeof(ro)-1u;r->path=pa;r->path_len=sizeof(pa);r->object_type=K501_OBJ_REGULAR_FILE;r->size_present=true;r->size_bytes=9u;r->content_present=true;memset(r->content_sha256,0x11u,32u);r->mtime_sec=0;r->mtime_nsec=0;r->mode=0644u;r->readable=true;
}
int main(void){k501_object_record_t r,d;const uint8_t*s,*ro,*pa;uint8_t*buf;size_t n,p,trash;make_record(&r,&s,&ro,&pa);if(!k501_object_record_compute_object_id(&r,r.object_id)||!k501_object_record_serialize(&r,&buf,&n))return 1;
    p=4u+r.schema_len+32u+4u+r.root_id_len+4u+r.path_len+1u;
    {uint8_t *x=malloc(n);if(!x){free(buf);return 1;}memcpy(x,buf,n);x[p]=2u;if(k501_object_record_decode(x,n,&d,&trash)){free(x);free(buf);puts("FAIL: invalid size presence accepted");return 1;}memcpy(x,buf,n);x[p+1u+8u]=2u;if(k501_object_record_decode(x,n,&d,&trash)){free(x);free(buf);puts("FAIL: invalid content presence accepted");return 1;}x[n-33u]=2u;if(k501_object_record_decode(x,n,&d,&trash)){free(x);free(buf);puts("FAIL: invalid readable value accepted");return 1;}free(x);}
    free(buf);puts("PASS: invalid presence/boolean values rejected");return 0;}
