#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/time.h>
#define TDIFF(start, end) ((end.tv_sec - start.tv_sec) * 1000000UL + (end.tv_usec - start.tv_usec))
int acnum[10000];
float bal[10000];

void fun(int ac1[], int ac2[], int type[], float amount[], int n){
	for(int i=0; i<n; i++){
		if(type[i]==1){
			bal[ac1[i]-1001]=bal[ac1[i]-1001]+amount[i]-(amount[i]/100);
			printf("acc number= %d balance= %f\n",ac1[i], bal[ac1[i]-1001]);
		}
		else if(type[i]==2){
			bal[ac1[i]-1001]=bal[ac1[i]-1001]-amount[i]-(amount[i]/100);
			printf("acc number= %d balance= %f\n",ac1[i], bal[ac1[i]-1001]);
		}
		else if(type[i]==3){
			bal[ac1[i]-1001]=1.071*bal[ac1[i]-1001];
			printf("acc number= %d balance= %f\n",ac1[i], bal[ac1[i]-1001]);
		}
		else if(type[i]==4){
			bal[ac1[i]-1001]=bal[ac1[i]-1001]-amount[i]-(amount[i]/100);
			bal[ac2[i]-1001]=bal[ac2[i]-1001]+amount[i]-(amount[i]/100);
			printf("acc number= %d balance= %f\n",ac1[i], bal[ac1[i]-1001]);
		}
	}
}


int main(int argc, char **argv){
	struct timeval start, end;
	char *a, *b;
	int n=atoi(argv[3]);
	a=argv[2];
	b=argv[1];
	int *tran, *type, *ac1, *ac2;
	float *amount;
	tran = (int*)malloc(sizeof(int)*n);
	type = (int*)malloc(sizeof(int)*n);
	amount = (float*)malloc(sizeof(float)*n);
	ac1 = (int*)malloc(sizeof(int)*n);
	ac2 = (int*)malloc(sizeof(int)*n);
	FILE *file1;
	file1 = fopen(a,"r");
	for(int i=0;i<n; i++){
		fscanf(file1, "%d %d %f %d %d\n",&tran[i], &type[i], &amount[i], &ac1[i], &ac2[i]);
	}
	//printf("%d %d %f %d %d\n",tran[0], type[0], amount[0], ac1[0], ac2[0]);
	//printf("%d %d %f %d %d\n",tran[1], type[1], amount[1], ac1[1], ac2[1]);
	//printf("%d %d %f %d %d\n",tran[2], type[2], amount[2], ac1[2], ac2[2]);
	FILE *file2;
	file2 = fopen(b,"r");
	for(int i=0; i<10000; i++){
		fscanf(file2,"%d %f",&acnum[i], &bal[i]);
	}
	//printf("%d %f\n",acnum[0], bal[0]);
	//printf("%d %f\n",acnum[1], bal[1]);
	gettimeofday(&start, NULL);
	fun(ac1, ac2, type, amount, n);
	gettimeofday(&end, NULL);
	printf("Time taken = %ld microsecs\n", TDIFF(start, end));
	return 0;
}
