#include <bits/stdc++.h>
using namespace std;

/*

Simple solution would be to perform count sort. We count the number of 0’s, 1’s and 2’s and then put them in the array in their correct order. The time complexity of above solution is O(n) but it requires two traversal of the array.

If current element is 0 place it in start. If 2 place it at end anf if 1 just ignore.
*/


// Linear-time partition routine to sort an array containing 0, 1 and 2
// It similar to three-way Partitioning for Dutch national flag problem
int threeWayPartition(int A[], int end)
{
	int start = 0, mid = 0;
	int pivot = 1;

	while (mid <= end)
	{
		if (A[mid] < pivot)			// current element is 0
		{
			swap(A[start], A[mid]);
			++start, ++mid;
		}
        
        
        /*
        
        we have not increased 1 in mid because the value which we got from the end may be zero that we need to check again. Thats why we have not increased mid just decreased end. 
        
        */
        
		else if (A[mid] > pivot)	// current element is 2
		{
			swap(A[mid], A[end]);
			--end;
		}
		else						// current element is 1
			++mid;
	}
}

// main function
int main()
{
	int A[] = { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 };
	int n = sizeof(A)/sizeof(A[0]);

	threeWayPartition(A, n - 1);

	for (int i = 0 ; i < n; i++)
		cout << A[i] << " ";

	return 0;
}
