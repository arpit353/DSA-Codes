#include <iostream>
using namespace std;

// DP solution to calculate maximum sum in the given array with
// no adjacent elements considered (Function uses extra space)
int maxSumSubseq(int arr[], int n)
{
    // base case
	if (n == 1)
		return arr[0];

    // create an auxiliary array to store solution of sub-problems
	int lookup[n];

	// lookup[i] stores the maximum sum possible till index i

	// trivial case
	lookup[0] = arr[0];
	lookup[1] = max(arr[0], arr[1]);

	// traverse array from index 2
	for (int i = 2; i < n; i++)
	{
	    // lookup[i] stores the maximum sum we get by

	    // 1. excluding current element and take maximum sum till index i-1
	    // 2. including current element arr[i] and take maximum sum till index i-2
		lookup[i] = max(lookup[i-1], lookup[i-2] + arr[i]);

		// if current element is more than maximum sum till current element
		lookup[i] = max(lookup[i], arr[i]);
	}

	// return maximum sum
	return lookup[n-1];
}

// main function
int main()
{
	int arr[] = { 1, 2, 9, 4, 5, 0, 4, 11, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Maximum sum is " << maxSumSubseq(arr, n);

	return 0;
}
