#include <iostream>
#include <algorithm>
using namespace std;

/*

This code is similar to the one we have studied in the start of finding if a sum exists in the array of 2 elements using sorting and pointer. The only difference here is we are fixing the start and subtracting the current element from the required sum and try to find the remaining sum exists in the remaining array or not.

*/

// Function to print all distinct triplet in the array with given sum
void printAllTriplets(int arr[], int n, int sum)
{
    // sort the array in ascending order
    sort (arr, arr + n);

    // check if triplet is formed by arr[i] and a pair from sub-array arr[i+1..n)
	for (int i = 0; i <= n - 3; i++)
	{
	    // remaining sum
		int k = sum - arr[i];

        // maintain two indexes pointing to end-points of the sub-array arr[i+1..n)
        int low = i + 1, high = n - 1;

		// loop till low is less than high
		while (low < high)
		{
            // increment low index if total is less than the remaining sum
            if (arr[low] + arr[high] < k)
				low++;

            // decrement high index is total is more than the remaining sum
			else if (arr[low] + arr[high] > k)
				high--;

			// triplet with given sum found
			else
			{
			    // print the triplet
				cout << "(" << arr[i] << " " << arr[low] << " " << arr[high] << ")\n";

				// increment low index and decrement high index
				low++, high--;
			}
		}
	}
}

// main function
int main()
{
	int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
	int sum = 6;

	int n = sizeof(arr) / sizeof(arr[0]);

	printAllTriplets(arr, n, sum);

	return 0;
}
