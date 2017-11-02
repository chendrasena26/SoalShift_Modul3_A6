#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
long long int sum;
int a;

void fak() {
	sum=1;
	for(int i=1;i<=a;i++) {
		sum=sum*i;
	}
}
