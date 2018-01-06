#include <bits/stdc++.h>
using namespace std;

/*

Given an array of integers, move all zeros present in the array to the end. The solution should maintain the relative order of items in the array.

For example,

Input:  { 6, 0, 8, 2, 3, 0, 4, 0, 1 }
Output: { 6, 8, 2, 3, 4, 1, 0, 0, 0 }

The idea is very simple. If the current element is non-zero, we can place the element at next available position in the array. After all elements in the array are processed, we fill all remaining indices by 0.
*/


// Function to move all zeros present in the array to the end
int Partition(int A[], int n)
{
	int j = 0;

	// each time we encounter a non-zero, j is incremented and
	// the element is placed before the pivot
	for (int i = 0; i < n; i++)
	{
		if (A[i] != 0)   // pivot is 0
		{
			swap(A[i], A[j]);
			j++;
		}
	}
}

// main function
int main()
{
	int A[] = { 6, 0, 8, 2, 3, 0, 4, 0, 1 };
	int n = sizeof(A) / sizeof(A[0]);

	Partition(A, n);

	for (int i = 0; i < n; i++)
		cout << A[i] << " ";

	return 0;
}
