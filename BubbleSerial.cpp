#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
#define MAX 1000 
int a[MAX]; 
double Runtime=0;
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver code
int main()
{
    for (int i = 0; i < MAX; i++)
	{
    	a[i]=rand()%500;
	}

    clock_t t1, t2; 

    t1 = clock(); 
    bubbleSort(a, MAX);
    t2= clock(); 
    cout<<"Sorted array: "; 
    cout << endl; 
    printArray(a, MAX);
    Runtime= (t2 - t1) / (double) CLOCKS_PER_SEC;
    cout <<endl<< "Time taken: " << Runtime << endl; 
    return 0;
}
