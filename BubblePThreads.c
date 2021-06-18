#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

int a[MAX], swapped = 0;
pthread_t thread[MAX];
double RunTime=0; 

void v_initiate() {
	int i;
	srand(time(NULL));
	for (int i = 0; i < MAX; i++)
	{
    	a[i]=rand()%500;
	}
}

void *bubble(void *i) {
	int tmp, mod;
	long x; 
	x=(long)i; 
	mod = x % 2;

	if (x != MAX-1) {
		if(a[x] > a[x+1]) {	
			tmp = a[x];
			a[x] = a[x+1];
			a[x+1] = tmp;
			swapped = 1;
		}
	}
	//printf("swap par: %d\nswap impar: %d\n", swapped_par, swapped_impar);
}

int main() {
	long i; 
	int par_impar = 0;
	v_initiate();
		
	clock_t t1, t2; 

    t1 = clock(); 
	do {

		swapped = 0;
		
		for(i = 0; i < MAX; i+=2)
			pthread_create(&thread[i], NULL, bubble, (void *)i);
		for(i = 0; i < MAX; i+=2)
			pthread_join(thread[i], NULL);

		swapped = 0;

		for(i = 1; i < MAX; i+=2)
			pthread_create(&thread[i], NULL, bubble, (void *)i);
		for(i = 1; i < MAX; i+=2)
			pthread_join(thread[i], NULL);

	//printf("swap par: %d - swap impar: %d\n", swapped_par, swapped_impar);

	} while(swapped == 1);
	t2=clock(); 
	
	printf("Sorted Array \n");
	for(i = 0; i < MAX; i++)
		printf("%d ", a[i]);
	printf("\n");
	RunTime= (t2 - t1) / (double) CLOCKS_PER_SEC;
    	printf("Time taken: %lf", RunTime); 
	exit(0);
}
