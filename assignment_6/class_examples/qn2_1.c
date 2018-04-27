#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<pthread.h>
int acnum[10000];
float bal[10000];

/*int acc(int tran[],int type[],int amount[],int ac1[],int ac2[], char *b){
	FILE *file2;
	file2 = fopen(b,"r");
	for(int i=0; i<10000; i++){
		fscanf(file2,"%d %d",&acnum[i], &bal[i]);
	}
	return 0;
}*/

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


/*int txn(char *a, char *b){
	int *tran, *type, *amount, *ac1, *ac2;
	train = (int*)malloc(sizeof(int)*n);
	type = (int*)malloc(sizeof(int)*n);
	amount = (int*)malloc(sizeof(int)*n);
	ac1 = (int*)malloc(sizeof(int)*n);
	ac2 = (int*)malloc(sizeof(int)*n);
	FILE *file1;
	file1 = fopen(a,"r");
	for(int i=0;i<n; i++){
		fscanf(file1, "%d %d %d %d %d\n",&tran[i], &type[i], &amount[i], &ac1[i], &ac2[i]);
	}
	return 0;
}*/
int main(int argc, char **argv){
	char *a, *b;
	int n=9;
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
	fun(ac1, ac2, type, amount, n);
	return 0;
}
