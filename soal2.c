#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_t treat[10];
char pem1[100], pem2[100];
int lub[16], skor1=0, skor2=0;
void namaewa() {
    gets(pem1);
    gets(pem2);
}

void tpem1() {
    int jum, temp;
        printf("Giliran "); puts(pem1);
    while(1) {
        printf("mau mengisi berapa lubang??");
        scanf("%d",&jum);
        if(jum<5) break;
    }
    while(jum--) {
        printf("masukkan posisi lubang yang ingin dimasukkan MINE");
        scanf("%d",&temp);
        lub[temp-1]=1;
    }
}

void tpem2() {
    int tebak;
    printf("Giliran "); puts(pem2);
    for(int i=0;i<4;i++) {
        scanf("%d",&tebak);
        if(lub[tebak-1]==1) {
            printf("Anda benar! Skor anda ditambah 1\n");
            skor2++;
        }
        else {
            printf("Anda salah, skor lawan ditambah 1\n");
            skor1++;
        }
    }
}


int main()
{
    namaewa();
    puts(pem1);
    puts(pem2);
}
