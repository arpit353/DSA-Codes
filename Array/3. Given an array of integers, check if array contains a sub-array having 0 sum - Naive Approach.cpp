#include <iostream>
#include <unordered_map>
using namespace std;

/*

Naive solution would be to consider all sub-arrays and find its sum. If sub-array sum is equal to 0, we print it. The time complexity of naive solution is O(n3) as there are n2 sub-arrays and it takes O(n) time to find sum of its elements. The method can be optimized to run in O(n2) time by calculating sub-array sum in constant time.

*/


// Function to print all sub-arrays with 0 sum present
// in the given array
void printallSubarrays(int arr[], int n)
{
    // consider all sub-arrays starting from i
	for (int i = 0; i < n; i++)
	{
        int sum = 0;

        // consider all sub-arrays ending at j
        for (int j = i; j < n; j++)
        {
            // sum of elements so far
            sum += arr[j];

            // if sum is seen before, we have found a sub-array with 0 sum
            if (sum == 0)
                cout << "Subarray [" << i << ".." << j << "]\n";
		}
	}
}

// main function
int main()
{
    int arr[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
	int n = sizeof(arr)/sizeof(arr[0]);

	printallSubarrays(arr, n);

	return 0;
}
