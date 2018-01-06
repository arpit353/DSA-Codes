#include <iostream>
using namespace std;

// Function to find equilibrium index of an array
void equilibriumIndex(int A[], int n)
{
    // left[i] stores sum of elements of sub-array A[0..i-1]
	int left[n];

	left[0] = 0;

	// traverse array from left to right
	for (int i = 1; i < n; i++)
		left[i] = left[i - 1] + A[i - 1];

    // right stores sum of elements of sub-array A[i+1..n)
	int right = 0;

	// traverse array from right to left
	for (int i = n - 1; i >= 0; i--)
	{
	    // if sum of elements of sub-array A[0..i-1] is equal to
	    // the sum of elements of sub-array A[i+1..n) i.e.
	    // (A[0] + A[1] + .. + A[i-1]) = (A[i+1] + A[i+2] + .. + A[n-1])

        if (left[i] == right)
			cout << "Equilibrium Index found at " << i << endl;

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
