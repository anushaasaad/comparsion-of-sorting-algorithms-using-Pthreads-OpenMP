#include <iostream> 
#include "omp.h" 
#include <time.h> 
#include <stdlib.h>
#define size 1000
using namespace std;
 
int arr[size]; 
int rand();
double Runtime=0;
 
void insertionSort(int arr[])
{
    #pragma omp prallel for
    {
    	    int i, key, j;
	    for (i = 1; i < size; i++)
	    {
		key = arr[i];
		j = i - 1;
		#pragma omp prallel
		{
			while (j >= 0 && arr[j] > key)
			{
			    arr[j + 1] = arr[j];
			    j = j - 1;
			}
		}
		arr[j + 1] = key;
	    }
    }
}

int main()
{    
    for (int i = 0; i < size; i++)
    {
   	arr[i]=rand()%500;
    }
    clock_t t1, t2; 
    t1 = clock(); 
    insertionSort(arr);
    t2 = clock(); 
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    Runtime= (t2 - t1) / (double) CLOCKS_PER_SEC;
    cout <<endl<< "Time taken: " << Runtime << endl; 
    return 0;
}

