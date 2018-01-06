#include<iostream>
using namespace std;

// Function to find contiguous sub-array with the largest sum
// in given set of integers (handles negative numbers as well)
int kadaneNeg(int arr[], int n)
{
    // stores maximum sum sub-array found so far
    int max_so_far = arr[0];

    // stores maximum sum of sub-array ending at current position
    int max_ending_here = arr[0];

    // traverse the given array
    for (int i = 1; i < n; i++)
    {
        // update maximum sum of sub-array "ending" at index i (by adding
        // current element to maximum sum ending at previous index i-1)
        max_ending_here = max_ending_here + arr[i];

        // maximum sum is should be more than the current element
        max_ending_here = max(max_ending_here, arr[i]);

        // update result if current sub-array sum is found to be greater
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main()
{
    int arr[] = { -8, -3, -6, -2, -5, -4 };
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "The sum of contiguous subarray with the largest sum is " <<
            kadaneNeg(arr, n);

    return 0;
}
