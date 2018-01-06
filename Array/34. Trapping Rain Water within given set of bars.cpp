#include <bits/stdc++.h>
using namespace std;


/*

The idea is to calculate maximum height bar on the left and right of every bar. Then the amount of water that can be stored on top of each bar is equal to minimum among maximum bar to the left and right minus height of current bar.

*/


// Function to find amount of water that can be trapped within
// given set of bars in linear time and extra space
int trap(int bars[], int n)
{
    int water = 0;

    // left[i] stores the maximum height of a bar to the left
	// of current bar
    int left[n-1];
    left[0] = INT_MIN;

	// process bars from left to right
    for (int i = 1; i < n - 1; i++)
        left[i] = max(left[i-1], bars[i-1]);

    /*
    int right[n];
    right[n - 1] = INT_MIN;
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i+1], bars[i+1]);

    for (int i = 1; i < n - 1; i++)
        if (min(left[i], right[i]) > bars[i])
            water += min(left[i], right[i]) - bars[i];
	*/

    // right stores the maximum height of a bar to the right
	// of current bar
    int right = INT_MIN;

	// process bars from right to left
    for (int i = n - 2; i >= 1; i--)
    {
        right = max(right, bars[i+1]);

        // check if it is possible to store water in current bar
        if (min(left[i], right) > bars[i])
            water += min(left[i], right) - bars[i];
    }

    return water;
}

// main function
int main()
{
    int heights[] = { 7, 0, 4, 2, 5, 0, 6, 4, 0, 5 };

    int n = sizeof(heights) / sizeof(heights[0]);

    cout << "Maximum amount of water that can be trapped is " << 
            trap(heights, n);

    return 0;
}
