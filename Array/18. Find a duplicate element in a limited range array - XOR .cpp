#include <bits/stdc++.h>
using namespace std;


/*

same elements will cancel out each other as a ^ a = 0
Also 0 ^ 0 = 0 and a ^ 0 = a
when we take xor with all these numbers it will cancel out all the terms. the duplicate element will we there 3 times so 2 of them will cancel out each other last one will be present.

*/


// Function to find a duplicate element in a limited range array
int findDuplicate(int A[], int n)
{
	int XOR = 0;

	// take xor of all array elements
	for (int i = 0; i < n; i++)
		XOR ^= A[i];

    // take xor of numbers from 1 to n-1
	for (int i = 1; i <= n-1; i++)
		XOR ^= i;

    // xor will contain the missing number
	return XOR;
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
