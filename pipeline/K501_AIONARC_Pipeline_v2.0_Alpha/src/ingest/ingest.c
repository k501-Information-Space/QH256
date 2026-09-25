#define _POSIX_C_SOURCE 200809L
#include "k501_aionarc/ingest.h"
#include "k501_aionarc/sha256.h"
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

static bool join_path(const uint8_t*b,size_t bl,const uint8_t*r,size_t rl,uint8_t**out){size_t n=bl+(rl?1u:0u)+rl;if(n>=PATH_MAX)return false;uint8_t*p=malloc(n+1u);if(!p)return false;memcpy(p,b,bl);if(rl){p[bl]='/';memcpy(p+bl+1u,r,rl);}p[n]=0u;*out=p;return true;}
static int cmp_obs(const void*a,const void*b){const k501_observation_t*x=a,*y=b;size_t n=x->path_len<y->path_len?x->path_len:y->path_len;int c=memcmp(x->path,y->path,n);if(c)return c;return x->path_len<y->path_len?-1:(x->path_len>y->path_len?1:0);}
static bool push(k501_observation_set_t*s,k501_observation_t*o){if(s->len==s->cap){size_t nc=s->cap?s->cap*2u:32u;void*p=realloc(s->items,nc*sizeof(*s->items));if(!p)return false;s->items=p;s->cap=nc;}s->items[s->len++]=*o;return true;}
static bool sha_file(const char*path,uint8_t out[32]){int fd=open(path,O_RDONLY|O_CLOEXEC);uint8_t buf[65536];ssize_t n;k501_sha256_ctx_t c;if(fd<0)return false;k501_sha256_init(&c);for(;;){n=read(fd,buf,sizeof buf);if(n<0){if(errno==EINTR)continue;(void)close(fd);return false;}if(n==0)break;k501_sha256_update(&c,buf,(size_t)n);}if(close(fd)!=0)return false;k501_sha256_final(&c,out);return true;}
static bool add_entry(const uint8_t*root,size_t root_len,const uint8_t*rel,size_t rel_len,k501_observation_set_t*out){uint8_t*full;struct stat st;k501_observation_t o={0};if(!join_path(root,root_len,rel,rel_len,&full))return false;if(lstat((const char*)full,&st)!=0){free(full);return false;}o.path=malloc(rel_len?rel_len:1u);if(!o.path){free(full);return false;}if(rel_len)memcpy(o.path,rel,rel_len);o.path_len=rel_len;o.mtime_sec=(int64_t)st.st_mtim.tv_sec;o.mtime_nsec=(int32_t)st.st_mtim.tv_nsec;o.mode=(uint32_t)(st.st_mode&07777u);
    if(S_ISREG(st.st_mode)){o.object_type=K501_OBJ_REGULAR_FILE;o.size_present=true;o.size_bytes=(uint64_t)st.st_size;if(sha_file((const char*)full,o.content_sha256)){o.content_present=true;o.readable=true;}}
    else if(S_ISDIR(st.st_mode)){o.object_type=K501_OBJ_DIRECTORY;DIR*d=opendir((const char*)full);if(d){o.readable=true;(void)closedir(d);}}
    else if(S_ISLNK(st.st_mode)){o.object_type=K501_OBJ_SYMLINK;o.readable=false;}
    else{o.object_type=K501_OBJ_OTHER;o.readable=false;}
    if(!push(out,&o)){free(o.path);free(full);return false;}
    if(o.object_type==K501_OBJ_DIRECTORY){DIR*d=opendir((const char*)full);if(d){struct dirent*e;while((e=readdir(d))!=NULL){if(strcmp(e->d_name,".")==0||strcmp(e->d_name,"..")==0)continue;size_t nl=strlen(e->d_name);size_t nrl=rel_len+(rel_len?1u:0u)+nl;uint8_t*nr=malloc(nrl?nrl:1u);if(!nr){closedir(d);free(full);return false;}if(rel_len){memcpy(nr,rel,rel_len);nr[rel_len]='/';}memcpy(nr+(rel_len?rel_len+1u:0u),e->d_name,nl);if(!add_entry(root,root_len,nr,nrl,out)){free(nr);closedir(d);free(full);return false;}free(nr);}closedir(d);}}
    free(full);return true;}
void k501_observation_set_free(k501_observation_set_t*s){size_t i;if(!s)return;for(i=0u;i<s->len;i++)free(s->items[i].path);free(s->items);memset(s,0,sizeof*s);}
bool k501_ingest_run(const uint8_t*root,size_t root_len,k501_observation_set_t*out){struct stat st;DIR*d;struct dirent*e;if(!root||!out||root_len==0u||root_len>=PATH_MAX)return false;memset(out,0,sizeof*out);if(lstat((const char*)root,&st)!=0||!S_ISDIR(st.st_mode))return false;d=opendir((const char*)root);if(!d)return false;while((e=readdir(d))!=NULL){if(strcmp(e->d_name,".")==0||strcmp(e->d_name,"..")==0)continue;{size_t nl=strlen(e->d_name);uint8_t*rel=malloc(nl?nl:1u);if(!rel){closedir(d);k501_observation_set_free(out);return false;}memcpy(rel,e->d_name,nl);if(!add_entry(root,root_len,rel,nl,out)){free(rel);closedir(d);k501_observation_set_free(out);return false;}free(rel);}}closedir(d);qsort(out->items,out->len,sizeof(out->items[0]),cmp_obs);return true;}
