#include<iostream>
using namespace std;

// Function to print contiguous sub-array with the largest sum
// in given set of integers
void kadane(int arr[], int n)
{
    // stores maximum sum sub-array found so far
    int max_so_far = 0;

    // stores maximum sum of sub-array ending at current position
    int max_ending_here = 0;

    // stores end-points of maximum sum sub-array found so far
    int start = 0, end = 0;

    // stores starting index of a positive sum sequence
    int beg = 0;

    // traverse the given array
    for (int i = 0; i < n; i++)
    {
        // update maximum sum of sub-array "ending" at index i
        max_ending_here = max_ending_here + arr[i];

        // if maximum sum is negative, set it to 0
        if (max_ending_here < 0)
        {
            max_ending_here = 0;    // empty sub-array
            beg = i + 1;
        }

        // update result if current sub-array sum is found to be greater
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = beg;
            end = i;
        }
    }

    cout << "The sum of contiguous sub-array with the largest sum is " <<
            max_so_far << endl;

    cout << "The contiguous sub-array with the largest sum is ";
    for (int i = start; i <= end; i++)
        cout << arr[i] << " ";
}

// main function
int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int n = sizeof(arr)/sizeof(arr[0]);

    kadane(arr, n);

    return 0;
}
