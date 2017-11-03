#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
#include <stdlib.h>
pthread_t thread[100];

void *cek() {
    FILE *f;
    int count=0,ch,len;
    char *w=(char*) word;
    if(NULL==(p=fopen("Novel.txt", "r")));
    len=strlen(word);
    for (;;) {
        int i;
        if(EOF==(ch=fgetc(f))) break;
        if((char)ch != *w) continue;
    	for(i=1;i<len;++i){
    	if(EOF==(ch = fgetc(f))) goto end;
    	if((char)ch != w[i]){
        	fseek(f, 1-i, SEEK_CUR);
        	goto next;
    	}
    }
    ++count;
    next: ;
    }
end:
    fclose(f);
    printf("%s : %d\n",w,count);
    return NULL;
}
int main()
{
    int err;
    err=pthread_create(&(tid[0]),NULL,&cek,NULL);
    if(err) printf("error ma bro\n");
    return 0;
}
