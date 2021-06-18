#include<iostream>
#include <time.h> 
#include <pthread.h> 
#include <stdlib.h>
#define size 1000
using namespace std;
 
int arr[size]; 
int rand();
double Runtime=0;

void insertionSort()
{
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
void* Sort(void *s)
{
	insertionSort();
	return 0;
}

int main()
{
    for (int i = 0; i < size; i++)
    {
   	arr[i]=rand()%500;
    }
    clock_t t1, t2; 
    pthread_t t;
    t1 = clock();
	pthread_create(&t,NULL,Sort,(void*)NULL);
	pthread_join(t,NULL);
    t2 = clock(); 
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    Runtime= (t2 - t1) / (double) CLOCKS_PER_SEC;
    cout <<endl<< "Time taken: " << Runtime << endl; 
    return 0;
}

