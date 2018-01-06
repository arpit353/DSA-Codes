#include <iostream>
#include <climits>
using namespace std;

// Function to find the length of smallest sub-array whose sum of
// elements is greater than the given number
int smallestSubarray(int arr[], int n, int k)
{
    // stores the current window sum
    int windowSum = 0;

    // stores the result
    int len = INT_MAX;

    // stores window's starting index
    int left = 0;

	// maintain a sliding window [left..right]
    for (int right = 0; right < n; right++)
    {
        // include current element in the window
        windowSum += arr[right];

        // (to handle negative numbers in the array)
        // if window's sum becomes negative, discard the window
        if (windowSum <= 0) // Kadane's algorithm
        {
            left = right;
            windowSum = 0;
        }

        // Try to make window sum greater than k and lengtb less as less as possible
        while (windowSum > k && left <= right)
        {
            // update the result if current window's length is less
            // than minimum found so far
            len = min(len, right - left + 1);

            // remove elements from the window's left side till window
            // becomes stable again
            windowSum -= arr[left];
            left++;
        }
    }

    // return result
    return len;
}

// main function
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int k = 21;   // positive number

    int n = sizeof(arr) / sizeof(arr[0]);

    // find length of the smallest sub-array
    int len = smallestSubarray(arr, n, k);

    if (len != INT_MAX)
        cout << "Smallest sub-array length is " << len;
    else
        cout << "No sub-array exists";

    return 0;
}
