#include <omp.h>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include<stdlib.h>
#include <ctime> 
using namespace std;
#define MAX 1000
double RunTime=0;
int arr[MAX];

void InsertSort(int arr[], int i, int length,  int half)
{
	//cout << ID << "   ";
	int temp = 0;
	int j = 0;

	for (int f = half + i; f < length; f = f + half)
	{
		j = f;
		while(j > i && arr[j-half] > arr[j])
		{
			temp = arr[j];
			arr[j] = arr[j-half];
			arr[j-half] = temp;
			j = j -half;
		}
	}
}
	
void shellSortParallel(int array[], int length)
{
	int h;
	int j = 0;
	int temp = 0;
	int i = 0;
	for(h =length/2; h > 0; h = h/2)
	{
		#pragma omp parallel for shared( array, length, h, i)  default(none)
		for( i = 0; i < h; i++)
		{
			//int ID = omp_get_thread_num();
			InsertSort(array, i, length, h);
		}
	}
}

int main()
{	
	
	double endTime = 0, startTime = 0; 
			
				for (int i = 0; i < MAX; i++)
				{
				    	arr[i]=rand()%500;
				}
						startTime = clock(); 
						shellSortParallel(arr, 1000);//Run the algorithm
				endTime = clock(); 
	cout<<"Elements of array after sorting \n";
	for(int i=0;i<MAX;i++)
	{
	cout<<" "<<arr[i]<<" ";
	}
	cout << endl; 
	RunTime = RunTime + (endTime - startTime)/((double)CLOCKS_PER_SEC);
	cout << "This is the time it took to run: " << RunTime << endl;// time in seconds
	return 0;

	
}




