#include <bits/stdc++.h>
using namespace std;

/*

Given an binary array, sort it in linear time and constant space. Output should print contain all zeroes followed by all ones.
 
For example,

Input: { 1, 0, 1, 0, 1, 0, 0, 1 }
Output:{ 0, 0, 0, 0, 1, 1, 1, 1 }

*/


/*

Simple solution would be to count number of 0’s present in the array (say k) and fill first k indices in the array by 0 and all remaining indices by 1.

Alternatively, we can also count number of 1’s present in the array (say k) and fill last k indices in the array by 1 and all remaining indices by 0.

*/


// Function to sort binary array in linear time
int Sort(int A[], int n)
{
    // count number of 0's
	int zeros = 0;
	for (int i = 0; i < n; i++)
		if (A[i] == 0)
			zeros++;

    // put 0's in the beginning
	int k = 0;
	while (zeros--)
		A[k++] = 0;

    // fill all remaining elements by 1
	while (k < n)
		A[k++] = 1;
}

// main function
int main()
{
	int A[] = { 0, 0, 1, 0, 1, 1, 0, 1, 0, 0 };
	int n = sizeof(A)/sizeof(A[0]);

	Sort(A, n);

	// print the rearranged array
	for (int i = 0 ; i < n; i++)
		cout << A[i] << " ";

    return 0;
}
