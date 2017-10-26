#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_t treat[10];
char pem1[100], pem2[100];
int lub[16], skor1=0, skor2=0;
void namaewa() {
    printf("Masukkan nama pemain1: ");
    gets(pem1);
    printf("Masukkan nama pemain2: ");
    gets(pem2);
}

void cetakskor() {
    printf("Skor "); puts(pem1); printf(": %d\n",skor1);
    printf("Skor "); puts(pem2); printf(": %d\n",skor2);
}
void tpem1() {
    int jum, temp;
        printf("Giliran "); puts(pem1);
    while(1) {
        printf("mau mengisi berapa lubang?? ");
        scanf("%d",&jum);
        if(jum<5) break;
        else printf("Kebanyakan. Hanya boleh 1 sampai 4 hehe\n");
    }
    while(jum--) {
        printf("masukkan posisi lubang yang ingin dimasukkan MINE ");
        while(1) {
        scanf("%d",&temp);
        if(temp<1||temp>16) printf("posisi lubang tak tersedia, ulangi input\n");
        else {
            lub[temp-1]=1;
            break;
        }
        }
    }
}

void tpem2() {
    int tebak;
    printf("Giliran "); puts(pem2);
    for(int i=0;i<4;i++) {
        printf("Masukkan posisi lubang yang ingin ditebak ");
        while(1) {
            scanf("%d",&tebak);
            if(tebak<1||tebak>16) {
                printf("Posisi lubang tak ada\n");
            }
            else break;
        }
        if(lub[tebak-1]==1) {
            printf("Anda benar! Skor anda ditambah 1\n");
            skor2++;
        }
        else {
            printf("Anda salah, skor lawan ditambah 1\n");
            skor1++;
        }
        cetakskor();
    }
}


int main()
{
    namaewa();
    tpem1();
    tpem2();
}
