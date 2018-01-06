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

In this we are using the concept of knapsack to print the permutation. We include the item recusrse for it then we add remove the item. 
*/


// Function to print the elements of a vector
void printVector(vector<int> out)
{
	for (int i: out)
		cout << i << " ";
	cout << endl;
}

// Function to print all distinct combinations of length k
void recurse(int arr[], vector<int> &out, int i, int n, int k)
{
	// base case: combination size is k
	if (k == 0) {
		printVector(out);
		return;
	}
	
	// return if no more elements are left 
	if (i == n)
		return;

	// include current element in the current combination and recurse
	out.push_back(arr[i]);
	recurse(arr, out , i + 1, n, k - 1);

	// exclude current element in the current combination
	out.pop_back();		// backtrack

	// uncomment below code to handle duplicates
	// while (arr[i] == arr[i+1])
	//   i++;

    // exclude current element in the current combination and recurse
	recurse(arr, out, i + 1, n, k);
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

	// vector to store combinations
	vector<int> vc;

	// process elements from left to right
	recurse(arr, vc, 0, n, k);

	return 0;
}
