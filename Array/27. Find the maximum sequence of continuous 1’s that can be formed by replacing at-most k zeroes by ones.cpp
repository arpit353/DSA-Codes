#include <bits/stdc++.h>
using namespace std;


/*

Same code as one we have done in the past just it has changed 2 to k. In previous code k value was fixed = 2.

*/

// Function to find the maximum sequence of continuous 1's by replacing
// atmost k 0's by 1 using sliding window technique
void longestSeq(bool arr[], int n, int k)
{
    int left = 0;       // left represents window's starting index
    int count = 0;      // stores number of zeros in current window

    int window = 0;     // stores maximum number of continuous 1's
                        // (including k zeroes)

    int leftIndex = 0;  // store left index of maximum window found

	// maintain a window [left..right] containing at-most k zeroes
    for (int right = 0; right < n; right++)
    {
        // if current element is 0, increase count of zeros in the
        // current window by 1
        if (arr[right] == 0)
            count++;

		// window becomes unstable if number of zeros in it becomes
		// more than k
        while (count > k)
        {
            // if we have found zero, decrement number of zeros in the
            // current window by 1
            if (arr[left] == 0)
                count--;

			// remove elements from the window's left side till window
			// becomes stable again
            left++;
        }

		// when we reach here, the window [left..right] contains at-most k
		// zeroes and we update max window size and leftmost index of the window
        if (right - left + 1 > window)
        {
            window = right - left + 1;
            leftIndex = left;
        }
    }

    // print maximum sequence of continuous 1's
    cout << "The longest sequence has length " << window << " from index "
            << leftIndex << " to " << (leftIndex + window - 1);
}

// main function
int main()
{
    bool arr[] = { 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0 };
    int k = 2;

    int n = sizeof(arr) / sizeof(arr[0]);

    longestSeq(arr, n, k);

    return 0;
}
