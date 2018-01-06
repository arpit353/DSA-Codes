#include <iostream>
using namespace std;

/*
Given an array of integers, find sub-array in it that has maximum product of its elements.
 
For example,
Input:  { -6, 4, -5, 8, -10, 0, 8 }

Output: The maximum product sub-array is {4, -5, 8, -10} having product 1600
Input:  { 40, 0, -20, -10 }
Output: The maximum product sub-array is {-20, -10} having product 200

*/

/*

A better solution will be to maintain two variables to store the maximum and minimum product ending at current position. Then we traverse the array once and for every index i in the array, we update maximum and minimum product ending at A[i]. We update the result if maximum product ending at any index if more than maximum product found so far.

*/

// Function to return maximum product of a sub-array of given array
int maxProduct(int arr[], int n)
{
    // maintain two variables to store maximum and minimum product
    // ending at current index
    int max_ending = 0, min_ending = 0;

	// to store maximum product sub-array found so far
    int max_so_far = 0;

    // traverse the given array
    for (int i = 0; i < n; i++)
    {
        int temp = max_ending;

        // update maximum product ending at current index
        max_ending = max(arr[i], max(arr[i] * max_ending,
                                    arr[i] * min_ending) );

        // update minimum product ending at current index
        min_ending = min(arr[i], min(arr[i] * temp,
                                     arr[i]* min_ending) );

        // cout << max_ending <<  " " << min_ending << endl;
        max_so_far = max(max_so_far, max_ending);
    }

    // return maximum product
    return max_so_far;
}

// main function
int main()
{
    int arr[] = { -6, 4, -5, 8, -10, 0, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The maximum product of a sub-array is " << maxProduct(arr, n);

    return 0;
}
