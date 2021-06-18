#include  <iostream>
#include <time.h> 
#include <stdlib.h>
#define MAX 1000
using namespace std;
int a[MAX]; 
int rand();
int part = 0; 
double Runtime=0;
/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}
 
void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}
 
int main()
{
    for (int i = 0; i < MAX; i++)
	{
    	a[i]=rand()%500;
	}
	//initial clock time 
    clock_t t1, t2; 
	//final clock time  
    shellSort(a, MAX);
    t2 = clock(); 
 
    cout << "\nArray after sorting: \n";
    printArray(a, MAX);
    Runtime= (t2 - t1) / (double) CLOCKS_PER_SEC;
    cout <<endl<< "Time taken: " << Runtime << endl; 
 
    return 0;
}
