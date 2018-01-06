#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, find maximum product of two integers in an array.

For example, consider array {-10, -3, 5, 6, -2}
Maximum product is formed by (-10, -3) or (5, 6) pair.

*/


/*

We are taking both maximum and minimum elements because elements can be negative.

*/

// Function to find maximum product of two integers in an array
void findMaximumProduct(int arr[], int n)
{
    // sort array in ascending order
	sort(arr, arr + n);

    // maximum product is formed by maximum of
    // 1. product of first two elements or
    // 2. product of last two elements
	if ((arr[0] * arr[1]) > (arr[n - 1] * arr[n - 2]))
		printf("Pair is (%d, %d)", arr[0], arr[1]);
	else
		printf("Pair is (%d, %d)", arr[n - 1], arr[n - 2]);
}

// main function
int main()
{
    int arr[] = { -10, -3, 5, 6, -20 };
	int n = sizeof(arr) / sizeof(arr[0]);

	findMaximumProduct(arr, n);

	return 0;
}
