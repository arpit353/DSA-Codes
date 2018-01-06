#include <bits/stdc++.h>
using namespace std;

/*

Given an array of integers, find all distinct combinations of given length.


For example,

Input:  {1, 2, 3}, k = 2
Output: {1, 2}, {1, 3}, {2, 3}
 

Input:  {1, 2, 1}, k = 2
Output: {1, 1}, {1, 2}

 

The program should print only distinct combinations. For example, for above input, either {1, 2} or {2, 1} should be considered.

In this we are not passing string by reference because string is already passed by pointer. Due to recusrion we are checking all the possibilities possible.

For ignoring duplicates we sort the array and skip the numbers which are same as the previous.

*/

// Function to print all distinct combinations of length k
void recurse(int arr[], string out, int i, int n, int k)
{
	// invalid input
	if (k > n)
		return;

	// base case: combination size is k 
	if (k == 0) {
		cout << out << endl;
		return;
	}
	
	// start from next index till last index
	for (int j = i; j < n; j++)
	{
		// add current element arr[j] to solution and recurse for next index 
		// (j+1) with one less element (k-1)
		recurse(arr, out + " " + to_string(arr[j]) , j + 1, n, k - 1);

		// uncomment below code to handle duplicates
		// while (arr[j] == arr[j + 1])
		//	j++;
	}
}

// main function
int main()
{
	int arr[] = { 1, 2, 3 };
	int k = 2;

	int n = sizeof(arr) / sizeof(arr[0]);

	// if array do not contain distinct elements,
	// sort the array to handle duplicates as combinations are asked 
	// sort (arr, arr + n);

	// process elements from left to right
	recurse(arr, "", 0, n, k);

	return 0;
}
