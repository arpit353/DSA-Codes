#include <bits/stdc++.h>
using namespace std;

/*

The longest bitonic subarray problem is to find a subarray of a given sequence in which the subarray’s elements are first sorted in in increasing order, then in decreasing order, and the subarray is as long as possible. Strictly ascending or descending subarrays are also accepted.

For example,

Longest Bitonic Subarray of sequence { 3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4 } is
{ 4, 5, 9, 10, 8, 5, 3 }

For sequences sorted in increasing or decreasing order, the output is same as the input sequence. i.e.

[1, 2, 3, 4, 5] —> [1, 2, 3, 4, 5]
[5, 4, 3, 2, 1] —> [5, 4, 3, 2, 1]
 
The idea is to maintain two arrays I[] and D[] –
I[i] stores the length of the longest increasing sub-array ending at arr[i]
 
D[i] stores the length of the longest decreasing sub-array starting from arr[i]
Finally, length of Longest Bitonic Subarray is maximum among all (I[i] + D[i] – 1). We can also keep track of two end-points of Longest Bitonic Subarray found so far to print LBS.

*/


// Function to find the Longest Bitonic Subarray in an array
int findBitonicSubarray(int A[], int n)
{
	// I[i] stores the length of the longest increasing sub-array
	// ending at A[i]
	int I[n + 1];
	I[0] = 1;
	for (int i = 1; i <= n; i++) {
		I[i] = 1;
		if (A[i-1] < A[i])
			I[i] = I[i-1] + 1;
	}

	// D[i] stores the length of the longest decreasing sub-array
	// starting with A[i]
	int D[n + 1];
	D[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		D[i] = 1;
		if (A[i] > A[i+1])
			D[i] = D[i+1] + 1;
	}

	// consider each element as peak and calculate LBS
	int lbs_len = 1;
	int beg = 0, end = 0;

	for (int i = 0; i <= n; i++)
    {
        if (lbs_len < I[i] + D[i] - 1)
        {
            lbs_len = I[i] + D[i] - 1;
            beg = i - I[i] + 1;
            end = i + D[i] - 1;
        }
    }

    // print longest bitonic sub-array
    printf("The length of longest bitonic sub-array is %d\n", lbs_len);
	printf("The longest bitonic sub-array is [%d, %d]", beg, end);

	return lbs_len;
}

// main function
int main()
{
	int A[] = { 3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4 };
	int n = sizeof(A) / sizeof(A[0]);

	findBitonicSubarray(A, n - 1);

	return 0;
}
