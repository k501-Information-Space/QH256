#define _POSIX_C_SOURCE 200809L
#include "k501_aionarc/ingest.h"
#include "k501_aionarc/object_record.h"
#include "k501_aionarc/qh256_mapping.h"
#include "k501_aionarc/history.h"
#include "k501_aionarc/bytes.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

static void hex(const uint8_t*p,size_t n,char*out){static const char h[]="0123456789abcdef";size_t i;for(i=0u;i<n;++i){out[2u*i]=h[p[i]>>4u];out[2u*i+1u]=h[p[i]&15u];}out[2u*n]='\0';}
static bool write_all(int fd,const uint8_t*p,size_t n){while(n){ssize_t k=write(fd,p,n);if(k<0){if(errno==EINTR)continue;return false;}if(k==0)return false;p+=k;n-=(size_t)k;}return true;}
static bool write_file(const char*path,const uint8_t*p,size_t n){int fd=open(path,O_WRONLY|O_CREAT|O_TRUNC|O_CLOEXEC,0644);if(fd<0)return false;if(!write_all(fd,p,n)){(void)close(fd);return false;}if(fsync(fd)!=0){(void)close(fd);return false;}return close(fd)==0;}
static bool framed(k501_buf_t*b,const uint8_t*p,size_t n){return n<=UINT32_MAX&&k501_buf_put_u32le(b,(uint32_t)n)&&k501_buf_put(b,p,n);}
static bool write_manifest(const char*path,const uint8_t*root_id,size_t root_len,const k501_observation_set_t*obs,const k501_object_record_t*rs,const k501_history_entry_t*hs){FILE*f=fopen(path,"wb");size_t i;if(!f)return false;char*rh=malloc(root_len*2u+1u);if(!rh){fclose(f);return false;}hex(root_id,root_len,rh);fprintf(f,"{\"schema\":\"K501-AIONARC-PIPELINE-2.0-ALPHA\",\"root_id_hex\":\"%s\",\"count\":%zu,\"records\":[",rh,obs->len);free(rh);for(i=0u;i<obs->len;++i){char oid[65],rec[65],qh[65],ch[65];hex(rs[i].object_id,32u,oid);hex(rs[i].record_hash,32u,rec);hex(hs[i].qh_state,32u,qh);hex(hs[i].chain_hash,32u,ch);if(i)fputc(',',f);fprintf(f,"{\"path_hex\":\"");{size_t j;for(j=0u;j<obs->items[i].path_len;++j)fprintf(f,"%02x",obs->items[i].path[j]);}fprintf(f,"\",\"object_id\":\"%s\",\"record_hash\":\"%s\",\"qh256_state\":\"%s\",\"chain_hash\":\"%s\"}",oid,rec,qh,ch);}fputs("]}\n",f);return fclose(f)==0;}

int main(int argc,char**argv){const char*root_path;const char*root_id="ROOT_TEST_V2_ALPHA";const char*out_dir;k501_observation_set_t obs={0};k501_object_record_t*records=NULL;k501_history_entry_t*history=NULL;k501_buf_t rb={0},hb={0};uint8_t prev[32]={0};size_t i;int rc=1;
    if(argc==5&&strcmp(argv[1],"--root-id")==0){root_id=argv[2];root_path=argv[3];out_dir=argv[4];}else if(argc==3){root_path=argv[1];out_dir=argv[2];}else{fprintf(stderr,"usage: %s [--root-id ID] ROOT OUTPUT_DIR\n",argv[0]);return 2;}
    printf("K501-AIONARC PIPELINE V2.0 ALPHA\nROOT: %s\nOUTPUT: %s\nROOT_ID: %s\n",root_path,out_dir,root_id);
    if(mkdir(out_dir,0755)!=0&&errno!=EEXIST){perror("mkdir");goto done;}
    if(!k501_ingest_run((const uint8_t*)root_path,strlen(root_path),&obs)){fprintf(stderr,"INGEST FAIL\n");goto done;}
    records=calloc(obs.len,sizeof(*records));history=calloc(obs.len,sizeof(*history));if(obs.len&&(!records||!history))goto done;
    for(i=0u;i<obs.len;++i){const uint8_t schema[] = K501_BOR_SCHEMA;k501_object_record_t*r=&records[i];qh256_t state;uint8_t*raw=NULL;size_t raw_len=0u;uint8_t next_prev[32];r->schema=schema;r->schema_len=sizeof(schema)-1u;r->root_id=(const uint8_t*)root_id;r->root_id_len=strlen(root_id);r->path=obs.items[i].path;r->path_len=obs.items[i].path_len;r->object_type=obs.items[i].object_type;r->size_present=obs.items[i].size_present;r->size_bytes=obs.items[i].size_bytes;r->content_present=obs.items[i].content_present;if(r->content_present)memcpy(r->content_sha256,obs.items[i].content_sha256,32u);r->mtime_sec=obs.items[i].mtime_sec;r->mtime_nsec=obs.items[i].mtime_nsec;r->mode=obs.items[i].mode;r->readable=obs.items[i].readable;if(!k501_object_record_compute_object_id(r,r->object_id)||!k501_object_record_serialize(r,&raw,&raw_len)||!k501_object_record_verify(raw,raw_len,r)||k501_aionarc_map_record_to_qh256(r,&state)||!k501_history_build((uint64_t)i,r,&state,prev,raw,raw_len,&history[i])){free(raw);goto done;}memcpy(next_prev,history[i].chain_hash,32u);if(!framed(&rb,raw,raw_len)){free(raw);goto done;}free(raw);memcpy(prev,next_prev,32u);{uint8_t*hs=NULL;size_t hs_len=0u;if(!k501_history_serialize(&history[i],&hs,&hs_len)||!framed(&hb,hs,hs_len)){free(hs);goto done;}free(hs);}}
    {char p[4096];if(snprintf(p,sizeof p,"%s/records.bin",out_dir)<0||!write_file(p,rb.data,rb.len))goto done;if(snprintf(p,sizeof p,"%s/history.bin",out_dir)<0||!write_file(p,hb.data,hb.len))goto done;if(snprintf(p,sizeof p,"%s/manifest.json",out_dir)<0||!write_manifest(p,(const uint8_t*)root_id,strlen(root_id),&obs,records,history))goto done;}
    printf("OBJECTS: %zu\nRESULT: PASS\n",obs.len);rc=0;
done:if(rc!=0)fprintf(stderr,"RESULT: FAIL\n");k501_buf_free(&rb);k501_buf_free(&hb);free(records);free(history);k501_observation_set_free(&obs);return rc;}
