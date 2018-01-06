#include <iostream>
using namespace std;


/*

We can solve this problem in constant space. Since the array contains all distinct elements except one and all elements lies in range 1 to n-1, we can check for duplicate element by marking array elements as negative by using array index as a key. For each array element arr[i], we get absolute value of the element abs(arr[i]) and invert the sign of element present at index abs(arr[i])-1. Finally, we traverse array once again and if a positive number is found at index i, then the duplicate element is i+1.

Above approach takes two traversals of the array. We can achieve the same in only one traversal. For each array element arr[i], we get absolute value of the element abs(arr[i]) and invert the sign of element present at index abs(arr[i])-1 if it is positive else if element is already negative, then it is a duplicate.

*/


// Function to find a duplicate element in a limited range array
int findDuplicate(int arr[], int n)
{
    int duplicate = -1;

    // do for each element in the array
    for (int i = 0; i < n; i++)
	{
	    // get absolute value of current element
		int absVal = (arr[i] < 0) ? -arr[i] : arr[i];

		// make element at index abs(arr[i]) - 1 negative if it is positive
		if (arr[absVal - 1] >= 0)
			arr[absVal - 1] = -arr[absVal - 1];
		else
        {
            // if element is already negative, it is repeated
			duplicate = absVal;
			break;
        }
	}

	// restore original array before returning
	for (int i = 0; i < n; i++)
	{
	    // make negative elements positive
	    if (arr[i] < 0)
            arr[i] = -arr[i];
	}

	// return duplicate element
	return duplicate;
}

// main function
int main()
{
    // input array contains n numbers between [1 to n - 1]
    // with one duplicate
	int arr[] = { 1, 2, 3, 4, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Duplicate element is " << findDuplicate(arr, n);

	return 0;
}
