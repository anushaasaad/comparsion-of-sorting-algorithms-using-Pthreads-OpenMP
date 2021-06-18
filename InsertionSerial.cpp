#include <iostream>
#include <time.h> 
#include <stdlib.h>
using namespace std;
#define MAX 1000
int a[MAX]; 
int rand();
double RunTime=0;  
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
/* Driver code */
int main()
{
	for (int i = 0; i < MAX; i++)
	{
    	a[i]=rand()%500;
	}

    clock_t t1, t2; 

    t1 = clock(); 
 
    insertionSort(a, MAX);
    t2=clock(); 
    printArray(a, MAX);
    RunTime= (t2 - t1) / (double) CLOCKS_PER_SEC;
    cout <<endl<< "Time taken: " << RunTime << endl; 

    return 0; 
 
}
 
