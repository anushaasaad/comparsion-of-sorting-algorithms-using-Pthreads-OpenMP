#include <stdlib.h>
#include <iostream>
#include <thread>
#include <ctime>
#include <vector>
using namespace std;
#define MAX 1000
void shellSort(vector <vector<int>>& wp, int k)
 {
    int n = wp[k].size();
    for (int gap = n / 2; gap > 0; gap /= 2)
    {

       for (int i = gap; i < n; i++)
        {
           int temp = wp[k][i];
           int j;
           for (j = i; j >= gap && wp[k][j - gap] > temp; j -= gap)
               wp[k][j] = wp[k][j - gap];
           wp[k][j] = temp;
        }
      }
}
vector <int> MergeFirst(vector <vector<int>>& wp, int a, vector <vector<int>>& wp2, int b)
{
	int n = wp[a].size();
	int m = wp2[b].size(); 
	vector<int> v3;
	int i, j; 
	i=j=0; 
	while (i < n && j < m) 
	{

		// comparing v1[i] and v2[j]
		// if v1[i] is smaller than v2[j]
		// push v1[i] to v3 and increment i
		// if v[i] is less than v2[j]
		// push v2[j] to v3 and increment j
		if (wp[a][i] <= wp2[b][j])
		 {
			v3.push_back(wp[a][i]);
			++i;
		}
		else
		{
			v3.push_back(wp2[b][j]);
			++j;
		}

	}

	// push the elements left in v1 to v3
	while (i < n) 
	{
		v3.push_back(wp[a][i]);
		++i;
	}

	// push the elements left in v2 to v3
	while (j < m) 
	{
		v3.push_back(wp2[b][j]);
		++j;
	}

	return v3;
}
vector<int> MergeSortedVectors(vector<int>& v1, vector<int>& v2) {

	// v3 is the output vector
	// it will store the merged vector obtained by merging v1 and v2
	vector<int> v3;

	int i, j, n, m;
	i = j = 0;
	n = v1.size();
	m = v2.size();

	// traverse each elemenst of v1 and v2
	while (i < n && j < m) {

		// comparing v1[i] and v2[j]
		// if v1[i] is smaller than v2[j]
		// push v1[i] to v3 and increment i
		// if v[i] is less than v2[j]
		// push v2[j] to v3 and increment j
		if (v1[i] <= v2[j]) {
			v3.push_back(v1[i]);
			++i;
		}
		else {
			v3.push_back(v2[j]);
			++j;
		}

	}

	// push the elements left in v1 to v3
	while (i < n) {
		v3.push_back(v1[i]);
		++i;
	}

	// push the elements left in v2 to v3
	while (j < m) {
		v3.push_back(v2[j]);
		++j;
	}

	return v3;

}
int main()
{
    int thN=4; 
    int i; 
    
    int* A = new int[MAX];
    for (i = 0; i < MAX; i++)
        A[i] = rand() % 500;

    thread* t = new thread[thN];

    vector<vector<int> > wp(thN, vector<int>());
    vector <int> v3, v4, v5; 

    int start = 0;
    for (i = 0; i < thN; i++)
    {
        for (int j = start; j < start + MAX / thN; j++)
        {
            wp[i].push_back(A[j]);
        }
        start += MAX / thN;
    }
    double endTime, startTime;
    startTime = clock();

    for (i = 0; i < thN; i++)
        t[i] = thread(shellSort,std::ref(wp),i);

    for (i = 0; i < thN; i++)
        t[i].join();
        v3 = MergeFirst(std::ref(wp), 0 , std::ref(wp), 1);
        v4 = MergeFirst(std::ref(wp), 2 , std::ref(wp), 3); 
	v5=MergeSortedVectors(v3, v4); 
	for (int i = 0; i < v5.size(); i++) 
	{
		cout << v5[i] << ' ';
	}


	
    endTime = clock();

    cout << "Runtime of shell sort: " << (endTime - startTime) / 1000 << endl;// time in miliseconds
    system("pause");
}

