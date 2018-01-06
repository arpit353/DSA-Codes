#include <iostream>
#include <climits>
using namespace std;

/*
We can solve this problem in linear time. The idea is to traverse the array from the right and keep track of maximum difference found so far. If the current element is less than the maximum element found so far and their difference is more than maximum difference found so far, then we update the maximum difference with current difference.
*/



// Function to calculate maximum difference between two elements in the array
// such that smaller element appears before the larger element in the array
int diff(int arr[], int n)
{
	int diff = INT_MIN;
	int max_so_far = arr[n-1];

	// traverse the array from right and keep track the maximum element
	for (int i = n - 2; i >= 0; i--)
	{
	    // update max if current element is greater than the maximum element
		if (arr[i] > max_so_far)
			max_so_far = arr[i];

        // if the current element is less than the maximum element,
        // then update the difference if required
        else
        	diff = max (diff, max_so_far - arr[i]);
	}

    // return difference
	return diff;
}

// main function
int main()
{
	int arr[] = { 2, 7, 9, 5, 1, 3, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "The maximum difference is " << diff(arr, n);

	return 0;
}
