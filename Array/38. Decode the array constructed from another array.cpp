#include <bits/stdc++.h>
using namespace std;


/* This has a unique solution just remenber it */

/*

Decode the array constructed from another array
Given an array constructed from another array by taking sum of every distinct pair in it, decode the array to get back the original array elements.
 
If the original array is A[0], A[1], . . , A[n-1], then the input array is

{ (A[0] + A[1]), (A[0] + A[2]), . . , (A[0] + A[n-1]),
  (A[1] + A[2]), (A[1] + A[3]), . . , (A[1] + A[n-1]),
   ..
   ..
   (A[i] + A[i+1]), (A[i] + A[i+2]), . . , (A[i] + A[n-1]),
   ..
   ..
   (A[n-2] + A[n-1]) }

For example,
Input:  { 3, 4, 5, 5, 6, 7 }
Output: { 1, 2, 3, 4 }
 
Input:  { 3, 4, 5, 6, 5, 6, 7, 7, 8, 9 }
Output: { 1, 2, 3, 4, 5 }
 
Input:  { 3 }
Output: { 1, 2 } or { 2, 1 }

Input:  { 3, 4, 5 }
Output: { 1, 2, 3 }
 
The idea is to calculate the first element of the original array by using the below relation

    A[0] = (inp[0] + inp[1] – inp[n-1]) / 2
As per problem constraints,

    inp[0] = A[0] + A[1]
    inp[1] = A[0] + A[2]
    inp[n-1] = A[1] + A[2]

Note that above relation works only when the size of the input array m is more than 2. For m <= 2, we need to separately handle the code.
 

Once we know the first element, we can easily derive the remaining elements of original array by using below relation

    A[i] = inp[i-1] – A[0]

Note: If m is the size of given array and n is size of the original array, then the relation between m and n is

m = n(n-1)/2 or n2 – n – 2m = 0

Solving above equation, we get

n = (sqrt(8m+1) + 1)/2

*/

// Function to decode given array to get back the original array elements
void decode(int inp[], int m)
{
	// calculate size of original array
	int n = (sqrt(8*m + 1) + 1) / 2;

	// create an auxillary array of size n to store elements
	// of the original array
	int A[n];

	// calculate the first element of the original array
	if (n == 1)
		A[0] = inp[0];
	else if (n == 2)
		A[0] = inp[0] - inp[1];
	else
		A[0] = (inp[0] + inp[1] - inp[n - 1]) / 2;

	// calculate the remaining elements of original array using
	// the first element
	for (int i = 1; i < n; i++)
		A[i] = inp[i - 1] - A[0];

	// print the original array
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
}

// main function
int main()
{
	int inp[] = { 3, 4, 5, 6, 5, 6, 7, 7, 8, 9 };
	int m = sizeof(inp)/sizeof(inp[0]);

	decode(inp, m);

	return 0;
}
