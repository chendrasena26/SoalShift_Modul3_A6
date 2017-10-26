#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
pthread_t tred[5];
int statuskep=100;
int statusloh=100;

void reductionkep() {
    while(statuskep>0) {
        sleep(20);
        statuskep-=10;
    }
}

void reductionloh() {
    while(statusloh>0) {
        sleep(10);
        statusloh-=15;
    }
}
void makani(int at) {
    if(at==1) statusloh+=10;
    else if(at==2) statuskep+=10;
}

void seken() {
    int at;
    while(statuskep>0&&statuskep<=100&&statusloh>0&&statusloh<=100) {
        scanf("%d", &at);
        makani(at);
    }
}

int main()
{
    return 0;
}
