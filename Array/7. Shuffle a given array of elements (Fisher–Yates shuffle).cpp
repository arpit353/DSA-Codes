#include <bits/stdc++.h>
using namespace std;

/*

Given an array of integers, in-place shuffle it. The algorithm should produce an unbiased permutation i.e. every permutation is equally likely.

Fisher–Yates shuffle is used to generate random permutations. It takes time proportional to the number of items being shuffled and shuffles them in place. Below is complete algorithm –

— To shuffle an array a of n elements :
for i from n-1 downto 1 do
    j = random integer such that 0 <= j <= i
    exchange a[j] and a[i]

*/


// Function to shuffle an array A of n elements
void shuffle(int A[], int n)
{
    // read array from highest index to lowest
    for (int i = n - 1; i >= 1; i--)
	{
	    // generate a random number j such that 0 <= j <= i
		int j = rand() % (i + 1);

		// swap current element with randomly generated index
		swap(A[i], A[j]);
	}
}

// main function
int main()
{
	int A[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(A) / sizeof(A[0]);

	// seed for random input
	srand(time(NULL));

	shuffle(A, n);

	// print the shuffled array
	for (int i = 0; i < n; i++)
		cout << setw(2) << A[i];

	return 0;
}
