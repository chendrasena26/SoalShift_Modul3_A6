#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_t treat[10];
char pem1[100], pem2[100];
int minesatu, minedua;
int skor1, skor2, a, status=0;
int lub1[16], lub2[16];
void namaewa() {
    status=0;
    printf("Masukkan nama pemain1: ");
    gets(pem1);
    printf("Masukkan nama pemain2: ");
    gets(pem2);
    status=1;
}

void cetakskor() {
    printf("Skor "); puts(pem1); printf(": %d\n",skor1);
    printf("Skor "); puts(pem2); printf(": %d\n",skor2);
}
void isi(int lub[]) {
    int jum, temp;
	if(minedua>16||skor1>=10||skor2>=10||minesatu>16);
	else {
	if(status==1) printf("Giliran Pemain 1\n");
	else if(status==2) printf("Giliran Pemain 2\n");
    while(1) {
        printf("mau mengisi berapa lubang?? ");
        scanf("%d",&jum);
        if(jum<5) {
	if(status==1) minesatu+=jum;
	else if(status==2) minedua+=jum;
	break;
	}
        else printf("Kebanyakan. Hanya boleh 1 sampai 4 hehe\n");
    }
    while(jum--) {
	if(minesatu>16||minedua>16) break;
        printf("masukkan posisi lubang yang ingin dimasukkan MINE ");
        while(1) {
        scanf("%d",&temp);
        if(temp<1||temp>16) printf("posisi lubang tak tersedia, ulangi input\n");
        else {
            if(lub[temp-1]==1) printf("lubang telah terpasang MINE hehe\n");
            else {
                lub[temp-1]=1;
                break;
            }
        }
        }
	}
    }
}

void tebak(int lub[], int *skorsatu, int *skordua) {
    int tebak;
	if(minedua>16||skor1>=10||skor2>=10||minesatu>16);
	else {
    if(status==3) printf("Giliran Pemain 1\n");
        else if(status==4) printf("Giliran Pemain 2\n");
    for(int i=0;i<4;i++) {
	if(skor1==10||skor2==10) break;
        while(1) {
	    printf("Masukkan posisi lubang yang ingin ditebak: ");
            scanf("%d",&tebak);
            if(tebak<1 || tebak>16) {
                printf("Posisi lubang tak ada, ulangi input\n");
            }
	    else if(lub[tebak-1]==2) printf("lubang sudah pernah ditebak hehe\n");
            else break;
        }
        if(lub[tebak-1]==1) {
            printf("Anda benar! Skor anda ditambah 1\n");
		lub[tebak-1]+=1;
            *skorsatu+=1;
        }
        else {
            printf("Anda salah, skor lawan ditambah 1\n");
            *skordua+=1;
        }
        cetakskor();
	}
    }
}

void* pemain1() {
	while(1) {
	if(minedua>16||skor1>=10||skor2>=10||minesatu>16) break;
    int *skorsatu,*skordua;
    skorsatu=&skor1;
    skordua=&skor2;
    while(status!=1) {}
    isi(lub1);
    status=2;
    while(status!=3) {}
    tebak(lub2,skorsatu,skordua);
    status=4;
	}
}

void* pemain2() {
	while(1) {
	if(minedua>16||skor1>=10||skor2>=10||minesatu>16) break;
    int *skorsatu,*skordua;
    skorsatu=&skor1;
    skordua=&skor2;
    while(status!=2) {}
    isi(lub2);
    status=3;
    while(status!=4) {}
    tebak(lub1,skordua,skorsatu);
	status=1;
	}
}

int main()
{
    int err;
    err=pthread_create( &(treat[0]), NULL, &namaewa, NULL);
    if(err) printf("error ma bro\n");
            err=pthread_create( &(treat[1]), NULL, &pemain1, NULL);
            if(err) printf("error ma bro\n");
            err=pthread_create( &(treat[2]), NULL, &pemain2, NULL);
            if(err) printf("error ma bro\n");

            pthread_join(treat[0],NULL);
            pthread_join(treat[1],NULL);
            pthread_join(treat[2],NULL);
		return 0;
}
