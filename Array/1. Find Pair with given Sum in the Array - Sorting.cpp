#include <bits/stdc++.h>
using namespace std;

// Function to find a pair in an array with given sum using Sorting
void findPair(int arr[], int n, int sum)
{
    // sort the array in ascending order
	sort(arr, arr + n);

	// maintain two indexes pointing to end-points of the array
	int low = 0;
	int high = n - 1;

	// reduce search space arr[low..high] at each iteration of the loop

	// loop till low is less than high
	while (low < high)
	{
		 if (arr[low] + arr[high] == sum)
		 {
			 cout << "Pair found ";
			 return;
		 }

		 // increment low index if total is less than the desired sum
		 // decrement high index is total is more than the sum
		 (arr[low] + arr[high] < sum)? low++: high--;
	}

	// No pair with given sum exists in the array
	cout << "Pair not found";
}

// main function
int main()
{
	int arr[] = { 8, 7, 2, 5, 3, 1};
	int sum = 10;

	int n = sizeof(arr)/sizeof(arr[0]);

	findPair(arr, n, sum);

	return 0;
}
