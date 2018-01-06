#include <bits/stdc++.h>
using namespace std;

/*

Instead of counting number of zeroes, if the current element is 0, we can place 0 at next available position in the array. After all elements in the array are processed, we fill all remaining indices by 1.

*/

// Function to sort binary array in linear time
int Sort(int A[], int n)
{
    // k stores index of next available position
	int k = 0;

	// do for each element
	for (int i = 0; i < n; i++)
	{
	    // if current element is zero, put 0 at next free
	    // position in the array
		if (A[i] == 0)
			A[k++] = 0;
	}

	// fill all remaining indexes by 1
	for (int i = k; i < n; i++)
		A[k++] = 1;
}

// main function
int main()
{
	int A[] = { 0, 0, 1, 0,1, 1, 0, 1, 0, 0 };
	int n = sizeof(A)/sizeof(A[0]);

	Sort(A, n);

	// print the rearranged array
	for (int i = 0 ; i < n; i++)
		cout << A[i] << " ";

    return 0;
}
