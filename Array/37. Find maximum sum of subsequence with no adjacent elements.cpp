#include <iostream>
#include <climits>
using namespace std;

/*

Given an array of integers, find the maximum sum of subsequence of given array where subsequence contains no adjacent elements.

For example,

Input:  { 1, 2, 9, 4, 5, 0, 4, 11, 6 }
Output: Maximum sum is 26
 
The maximum sum is formed by subsequence {1, 9, 5, 11}
 
The problem is similar to 0/1 Knapsack problem where for every item, we have two choices – to include that element in the solution or to exclude that element from solution. We can solve this problem by following the same logic. The only difference is that we include current element only if it is not adjacent to previous element considered.

*/

// Function to calculate maximum sum in the given array
// with no adjacent elements considered
// i --> index of current element
// prev --> index of previous element included in sum
int maxSumSubseq(int arr[], int i, int n, int prev)
{
    // base case: all elements are processed
	if (i == n)
		return 0;

    // recurse by excluding current element
	int excl = maxSumSubseq(arr, i + 1, n, prev);

	int incl = 0;

	// include current element only if it is not adjacent
	// to previous element considered
	if (prev + 1 != i)
		incl = maxSumSubseq(arr, i + 1, n, i) + arr[i];

    // return maximum sum we get by including or excluding
    // current item
	return max(incl, excl);
}

// main function
int main()
{
	int arr[] = { 1, 2, 9, 4, 5, 0, 4, 11, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Maximum sum is " << maxSumSubseq(arr, 0, n, INT_MIN);

	return 0;
}
