#include <iostream> 
#include "omp.h" 
#include <time.h> 
#include <stdlib.h>
#define MAX 1000

using namespace std; 
int a[MAX]; 
int rand();


void merge(int low, int mid, int high) 
{ 
    int* left = new int[mid - low + 1]; 
    int* right = new int[high - mid]; 

    int n1 = mid - low + 1, n2 = high - mid, i, j; 


    for (i = 0; i < n1; i++) 
        left[i] = a[i + low]; 



    for (i = 0; i < n2; i++) 
        right[i] = a[i + mid + 1]; 

    int k = low; 
    i = j = 0; 

    while (i < n1 && j < n2) { 
        if (left[i] <= right[j]) 
            a[k++] = left[i++]; 
        else
            a[k++] = right[j++]; 
    } 

    while (i < n1) { 
        a[k++] = left[i++]; 
    } 
    while (j < n2) { 
        a[k++] = right[j++]; 
    } 
} 

void merge_sort(int low, int high) 
{ 
    int mid = low + (high - low) / 2; 
    if (low < high) { 

    #pragma omp task firstprivate (low, high)
        merge_sort(low, mid);
        
    #pragma omp task firstprivate (low, high)
        merge_sort(mid + 1, high); 
        
    #pragma omp taskwait
        merge(low, mid, high); 
    } 
} 
int main() 
{ 
    for (int i = 0; i < MAX; i++)
	{
    	a[i]=rand()%1000;
  	}
    double t1, t2; 

    t1 = omp_get_wtime();

    #pragma omp parallel
{
    #pragma omp single
    merge_sort(0, MAX-1);
}
    t2 = omp_get_wtime(); 

    cout << "Sorted array: "<<endl; 
    for (int i = 0; i < MAX; i++) 
    {
    	cout << a[i] << " " ; 
    	}
    	cout << endl; 
    

    cout <<endl<< "Time taken: " << (t2 - t1) / (double)CLOCKS_PER_SEC << endl; 
    return 0; 
}


