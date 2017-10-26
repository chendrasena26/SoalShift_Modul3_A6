#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
pthread_t tred[5];
int statuskep=100;
int statusloh=100;
int at=0;

void *reductionkep() {
   while(statuskep>0||statuskep<=100) {
        sleep(20);
        statuskep-=10;
   }
}

void *reductionloh() {
   while(statusloh>0||statusloh<=100) {
        sleep(10);
        statusloh-=15;
   }
}

void *seken() {
   while(1) {
    scanf("%d",&at);
    //fflush(stdin);
    if(at==1) statuskep+=10;
    else if(at==2) statusloh+=10;
   if(statuskep<=0||statuskep>100||statusloh<=0||statusloh>100) break;
    printf("kepiting: %d  lohan: %d \n",statuskep,statusloh);
   }
}

int main()
{
//while(1) {
    int err;
	//fflush(stdout);
	sleep(1);
	//system("clear");
	//scanf("%d",&at);
	//fflush(stdin);
    err=pthread_create(&(tred[0]),NULL,&reductionkep,NULL);
    if(err!=0) printf("threadnya error\n");
    err=pthread_create(&(tred[1]),NULL,&reductionloh,NULL);
    if(err!=0) printf("threadnya error\n");
   // while(1) {
    //scanf("%d",&at);
    err=pthread_create(&(tred[2]),NULL,&seken,NULL);
    if(err!=0) printf("threadnya error\n");
    //printf("kepiting: %d  lohan: %d \n",statuskep,statusloh);
    //if(statuskep<=0||statuskep>100||statusloh<=0||statusloh>100) break;
    //}

	//pthread_join(tred[0],NULL);
	//pthread_join(tred[1],NULL);
	pthread_join(tred[2],NULL);
	//printf("hehe\n");
    //if(statusloh>100||statusloh<=0||statuskep>100||statuskep<=0) break;
	//}
	return 0;
}
