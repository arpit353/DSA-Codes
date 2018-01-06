#include<iostream>
#include<climits>
using namespace std;

/*

Given an array of integers, find the smallest window in array sorting which will make the entire array sorted in increasing order.

For example,

Input:  { 1, 2, 3, 7, 5, 6, 4, 8 }
Output: Sort the array from index 3 to 6
 

Input:  { 1, 3, 2, 7, 5, 6, 4, 8 }
Output: Sort the array from index 1 to 6

*/

/*

We can easily solve this problem in linear time. Below is the complete algorithm –

1. Traverse array from left to right keeping track of maximum so far and note the last encountered index j which is less than the maximum so far.
2. Traverse array from right to left keeping track of minimum so far and note the last encountered index i which is more than the minimum so far.

3. Finally we sort the array from index i to j
 
For example, consider below array

   { 1, 2, 3, 7, 5, 6, 4, 8 }

If we traverse the array from left to right, the last encountered index which is less than the maximum so far is 6. Similarly, if we traverse the array from right to left, the last encountered index which is more than the minimum so far is 3. So, we need to sort the array from index 3 to 6.


*/


// Function to find the smallest window in the array sorting which will
// make the entire array sorted
void findSubarray(int arr[], int n)
{
	int leftIndex = -1, rightIndex = -1;

	// traverse from left to right and keep track of maximum so far
	int max_so_far = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (max_so_far < arr[i])
			max_so_far = arr[i];

		// find the last position that is less than the maximum so far
		if (arr[i] < max_so_far)
			rightIndex = i;
	}

	// traverse from right to left and keep track of minimum so far
	int min_so_far = INT_MAX;
	for (int i = n - 1; i >= 0; i--)
	{
		if (min_so_far > arr[i])
			min_so_far = arr[i];

		// find the last position that is more than the minimum so far
		if (arr[i] > min_so_far)
			leftIndex = i;
	}

	cout << "Sort array from index " << leftIndex << " to " << rightIndex;
}

// main function
int main()
{
	int arr[] = { 1, 3, 2, 7, 5, 6, 4, 8 };
	int n = sizeof(arr)/sizeof(arr[0]);

	findSubarray(arr, n);

	return 0;
}
