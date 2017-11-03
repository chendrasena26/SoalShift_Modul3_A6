#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
long long int sum, total[100];
int a, xxx=1;
int inputan[100];
pthread_t tred;

void fak() {
	sum=1;
	for(int i=1;i<=a;i++) {
		sum=sum*i;
	}
	total[xxx]=sum;
	xxx++;
}

void sortprint(int argc) {
	for(int x=1;x<argc;x++) {
		for(int y=1;y<argc-1;y++) {
		if(inputan[y]>inputan[y+1]) {
			int tempinp;
			long long int tempsum;
			tempinp=inputan[y];
			inputan[y]=inputan[y+1];
			inputan[y+1]=tempinp;
			tempsum=total[y];
			total[y]=total[y+1];
			total[y+1]=tempsum;
			}
		}
	printf("Hasil %d! : %lld\n",inputan[x],total[x]);
	}
}

int main(int argc, const char *argv[]) {
	int i;
	for(i=1;i<argc;i++) {
		inputan[i] = atoi(argv[i]);
		a=inputan[i];
		pthread_create(&tred, NULL, fak, NULL);
		pthread_join(tred, NULL);
	}
	sortprint(argc);
	return 0;
}
