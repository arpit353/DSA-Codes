#include <bits/stdc++.h>
using namespace std;

/*

We can solve this problem by using sliding window technique. The idea is to maintain a window containing at-most one zero at any point. We add elements to the window from right until it becomes unstable. The window becomes unstable if number of zeros in it becomes 2 and we remove elements from its left side till it becomes stable again (by removing leftmost zero). If the window is stable and current window length is more than maximum window found so far, we update the index of 0 to be replaced.


*/


// Find index of 0 to replaced with 1 to get maximum sequence
// of continuous 1's using sliding window technique
int findIndexofZero(int arr[], int n)
{
    int left = 0;               // left represents window's starting index
    int count = 0;              // stores number of zeros in current window

    int max_count = 0;           // stores maximum number of 1's (including zero)
    int max_index = -1;         // stores index of 0 to be replaced
    int prev_zero_index;        // stores index of previous zero

    // maintain a window [left..i] containing at-most one zero
    for (int i = 0; i < n; i++)
    {
        // if current element is 0, update prev_zero_index and
        // increase count of zeros in current window by 1
        if (arr[i] == 0)
            prev_zero_index = i,
            count++;

        // window becomes unstable if number of zeros in it becomes 2
        if (count == 2)
        {
            // remove elements from the window's left side till we found a zero
            while (arr[left])
                left++;

            left++;     // remove leftmost 0 so that window becomes stable again
            count = 1;  // decrement count as 0 is removed
        }

        // when we reach here, the window [left..i] contains only at-most one zero
        // we update maximum count and index of 0 to be replaced if required
        if (i - left + 1 > max_count)
        {
            max_count = i - left + 1;
            max_index = prev_zero_index;
        }
    }

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
