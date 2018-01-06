#include <bits/stdc++.h>
using namespace std;

/*

Given an array of integers, find maximum length sub-array having given sum.
For example, consider below array

A[] = { 5, 6, -5, 5, 3, 5, 3, -2, 0 }
Sum = 8

Sub-arrays with sum 8 are

{ -5, 5, 3, 5 }
{ 3, 5 }
{ 5, 3 }

The longest subarray is { -5, 5, 3, 5 } having length 4

*/


/*

This is same as the first question but now we are also storing the length.

We can use map to solve this problem in linear time. The idea is to create an empty map to store ending index of first sub-array having given sum. We traverse the given array, and maintain sum of elements seen so far.

If sum is seen for first time, insert the sum with its index into the map.
If (sum – S) is seen before, there exists a sub-array with given sum which ends at current index and we update maximum length sub-array having sum S if current sub-array has more length.

*/


// Function to find maximum length sub-array with sum S present
// in the given array
void maxLengthSubArray(int arr[], int n, int S)
{
	// create an empty multi-map to store ending index of first sub-array
	// having some sum
	unordered_map<int, int> map;

	// insert (0, -1) pair into the set to handle the case when sub-array
	// with sum S starts from index 0
	map[0] = -1;

	int sum = 0;

	// len stores the maximum length of sub-array with sum S
	int len = 0;

	// stores ending index of maximum length sub-array having sum S
	int ending_index = -1;

	// traverse the given array
	for (int i = 0; i < n; i++)
	{
		// sum of elements so far
		sum += arr[i];

		// if sum is seen for first time, insert sum with its index into the map
		if (map.find(sum) == map.end())
			map[sum] = i;

		// update length and ending index of maximum length sub-array having sum S
		if (map.find(sum - S) != map.end() && len < i - map[sum - S])
		{
			len =  i - map[sum - S];
			ending_index = i;
		}
	}

	// print the sub-array
	cout << "[" << (ending_index - len + 1) << ", " << ending_index << "]";
}

int main()
{
	int arr[] = { 5, 6, -5, 5, 3, 5, 3, -2, 0 };
	int sum = 8;

	int n = sizeof(arr) / sizeof(arr[0]);

	maxLengthSubArray(arr, n, sum);

	return 0;
}
