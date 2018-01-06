#include <bits/stdc++.h>
using namespace std;

/*

Given an array of integers, find maximum product of two integers in an array.

For example, consider array {-10, -3, 5, 6, -2}
Maximum product is formed by (-10, -3) or (5, 6) pair.

*/

// Function to find maximum product of two integers in an array
void findMaximumProduct(int arr[], int n)
{
    // Find maximum and second maximum element in an array
	int max1 = arr[0], max2 = INT_MIN;

	for (int i = 1; i < n; i++)
	{
	    // if current element is more than the maximum element,
	    // update maximum and second maximum element
		if (arr[i] > max1)
		{
			max2 = max1;   // Game point
			max1 = arr[i];
		}

		// if current element is less than maximum but greater than second
		// maximum element, update second maximum element
        else if (arr[i] > max2)
		{
			max2 = arr[i];
		}

		// else ignore the element
	}


    // Find minimum and second minimum element in an array
	int min1 = arr[0], min2 = INT_MAX;

	for (int i = 1; i < n; i++)
	{
	    // if current element is more than the minimum element,
	    // update minimum and second minimum element
        if (arr[i] < min1)
		{
			min2 = min1;  // Game point
			min1 = arr[i];
		}

		// if current element is less than minimum but greater than second
		// minimum element, update second minimum element
		else if (arr[i] < min2)
			min2 = arr[i];

        // else ignore the element
	}

    // Maximum product is formed by maximum of
    // 1. product of maximum and second maximum element or
    // 2. product of minimum and second minimum element
	if (max1 * max2 > min1 * min2)
		printf("Pair is (%d, %d)", max1, max2);
	else
		printf("Pair is (%d, %d)", min1, min2);
}

// main function
int main()
{
    int arr[] = { -10, -3, 5, 6, -20 };
	int n = sizeof(arr) / sizeof(arr[0]);

	findMaximumProduct(arr, n);

	return 0;
}
