#include <iostream>
using namespace std;


/*

The idea is very simple. We update each non-zero element of array with count of its adjacent consecutive 1’s. For example, array { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 } is converted to { 0, 0, 1, 0, 3, 3, 3, 0, 2, 2 }. Now the problem reduces to finding the index of 0 whose sum of left and right element is maximum.

*/

// Find index of 0 to replaced with 1 to get maximum sequence of continuous 1's
int findIndexofZero(int arr[], int n)
{
	// arr[i] now stores the length of consecutive 1's ending at arr[i]
	for (int i = 1; i < n; i++)
		if (arr[i] == 1)
			arr[i] += arr[i - 1];

	int count = 0;

	// traverse the array from right to left
	for (int i = n - 1; i >= 0; i--)
	{
	    // update count to number of adjacent 1's which includes the
	    // current element
		count = max(arr[i], count);

		// update array with count of adjacent 1's for each non-zero element
        if (arr[i])
			arr[i] = count;
		else
            // reset the count if current element is 0
            count = 0;
	}

	int max_count = 0;          // for maximum number of 1 including zero
	int max_index = -1;         // stores index of 0 to be replaced

	// consider each index i of the array
	for (int i = 0; i < n; i++)
	{
		// if current element is 0
        if (arr[i] == 0)
		{
		    // update maximum count and index of 0 to be replaced if required
		    // by taking left and right element count

			if (i == 0 && max_count < arr[i + 1] + 1)
				max_count = arr[i + 1] + 1,
				max_index = i;

			else if (i == n - 1 && max_count < arr[i - 1] + 1)
				max_count = arr[i - 1] + 1,
				max_index = i;

			else if (max_count < arr[i - 1] + arr[i + 1] + 1)
				max_count = arr[i - 1] + arr[i + 1] + 1,
				max_index = i;
		}
	}

	// restore the original array
	for (int i = 1; i < n; i++)
		if (arr[i])
			arr[i] = 1;

	// return index of 0 to be replaced or -1 if array contains all 1's
	return max_index;
}

// main function
int main()
{
	int arr[] = { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int index = findIndexofZero(arr, n);

	if (index != -1)
		cout << "Index to be replaced is " << index;
	else
		cout << "Invalid input";

	return 0;
}
