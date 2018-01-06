#include <iostream>
#include <numeric>
using namespace std;

/*
Same as previous code just we have taken the whole sum in the start. If in a subarry its sum is equal to total minus its sum, that means both are equal and equilibrium is reached.

*/


// Optimized method to find equilibrium index of an array
void equilibriumIndex(int A[], int n)
{
	// total stores sum of all elements of the array
	int total = accumulate(A, A + n, 0);

	/* int total = 0;
	for (int i = 0; i < n; i++)
		total += A[i]; */

	// right stores sum of elements of sub-array A[i+1..n)
	int right = 0;

	// traverse array from right to left
	for (int i = n - 1; i >= 0; i--)
	{
		// i is equilibrium index if sum of elements of sub-array A[0..i-1]
		// is equal to the sum of elements of sub-array A[i+1..n) i.e.
		// (A[0] + A[1] + .. + A[i-1]) = (A[i+1] + A[i+2] + .. + A[n-1])

        // sum of elements of left sub-array A[0..i-1] is (total - (A[i] + right))
		if (right == total - (A[i] + right))
			cout << "Equilibrium Index found " << i << endl;

        // new right = A[i] + (A[i+1] + A[i+2] + .. + A[n-1])
		right += A[i];
	}
}

// main function
int main()
{
	int A[] = { 0, -3, 5, -4, -2, 3, 1, 0 };
	int n = sizeof(A) / sizeof(A[0]);

	equilibriumIndex(A, n);

	return 0;
}
