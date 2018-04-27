#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/time.h>
#define TDIFF(start, end) ((end.tv_sec - start.tv_sec) * 1000000UL + (end.tv_usec - start.tv_usec))
int acnum[10000];
float bal[10000];
int *tran, *type, *ac1, *ac2;
	float *amount;
	int n;
struct thread_param{
	pthread_t tid;
	int thread_ctr;
	int skip;
};
pthread_mutex_t lock;
int thread_num=0;
	int it=0;

void* fun(){

	while(1){
		pthread_mutex_lock(&lock);
		if(it>n-1){
			pthread_mutex_unlock(&lock);
			break;
		}
		if(type[it]==1){
			bal[ac1[it]-1001]=bal[ac1[it]-1001]+amount[it]-(amount[it]/100);
			//printf("acc number= %d balance= %f\n",ac1[it], bal[ac1[it]-1001]);
			it++;
		}
		else if(type[it]==2){
			bal[ac1[it]-1001]=bal[ac1[it]-1001]-amount[it]-(amount[it]/100);
			//printf("acc number= %d balance= %f\n",ac1[it], bal[ac1[it]-1001]);
			it++;
		}
		else if(type[it]==3){
			bal[ac1[it]-1001]=1.071*bal[ac1[it]-1001];
			//printf("acc number= %d balance= %f\n",ac1[it], bal[ac1[it]-1001]);
			it++;
		}
		else if(type[it]==4){
			bal[ac1[it]-1001]=bal[ac1[it]-1001]-amount[it]-(amount[it]/100);
			bal[ac2[it]-1001]=bal[ac2[it]-1001]+amount[it]-(amount[it]/100);
			//printf("acc number= %d balance= %f\n",ac1[it], bal[ac1[it]-1001]);
			it++;
		}
		pthread_mutex_unlock(&lock);
			
	}
	pthread_exit(NULL);
}


int main(int argc, char **argv){
	struct timeval start, end;
	char *a, *b;
	n=atoi(argv[3]);
	thread_num = atoi(argv[4]);
	a=argv[2];
	b=argv[1];
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
	pthread_t *threads;
	threads=(pthread_t*)malloc(thread_num*sizeof(pthread_t));
	pthread_mutex_init(&lock, NULL);
	int *cbuff;
	int k=2;
	cbuff=&k;
	int ctr;
	gettimeofday(&start, NULL);
	for(ctr=0; ctr < thread_num; ++ctr){
        if(pthread_create(&threads[ctr], NULL, fun, cbuff) != 0){
              perror("pthread_create");
              exit(-1);
        	}
 		}
     
    for(ctr=0; ctr < thread_num; ++ctr)
        pthread_join(threads[ctr], NULL);

 	for (int i = 0; i < 10000; ++i)
 	{
 		printf("%d %0.2f\n",acnum[i], bal[i]);
 	}
	//fun(n);
	gettimeofday(&end, NULL);
	printf("Time taken = %ld microsecs\n", TDIFF(start, end));
	return 0;
}
