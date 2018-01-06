#include<iostream>
using namespace std;

// Function to print sub-array having given sum using
// sliding window technique
void findSubarray(int arr[], int n, int sum)
{
    // maintains sum of current window
	int windowSum = 0;

    // maintain a window [low, high-1]
	int low = 0, high = 0;

	// consider every sub-array starting from low index
	for (low = 0; low < n; low++)
	{
		// if current window's sum is less than the given sum,
		// then add elements to current window from right
		while (windowSum < sum && high < n)
		{
			windowSum += arr[high];
			high++;
		}

        // if current window's sum is equal to the given sum
		if (windowSum == sum)
        {
            cout << "Subarray found [" << low << "-" << high - 1 << "]\n";
            return;
        }

        // At this point the current window's sum is more than the given sum
        // remove current element (leftmost element) from the window
		windowSum -= arr[low];
	}
}

// main function
int main()
{
    // array of positive integers
	int arr[] = { 2, 6, 0, 9, 7, 3, 1, 4, 1, 10 };
	int sum = 15;

    int n = sizeof(arr)/sizeof(arr[0]);

	findSubarray(arr, n, sum);

	return 0;
}
