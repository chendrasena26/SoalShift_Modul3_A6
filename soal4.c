#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
long long int sum=1;
int a;
pthread_t tred[10];

void fak() {
	sum=1;
	for(int i=1;i<=a;i++) {
		sum=sum*i;
	}
	printf("Hasil %d! : %lld\n",a,sum);
}

int main() {
	int i=0;
	while(1) {
		scanf("%d",&a);
		pthread_create(&(tred[i]), NULL, fak, NULL);
		pthread_join(tred[i], NULL);
		i++;
	}
	return 0;
}
