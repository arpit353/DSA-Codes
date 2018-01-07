#include <stdio.h>

/*

We can solve this problem in one traversal of array and in O(1) space. The idea is to use XOR operator. We know that if we XOR a number with itself odd number of times the result is number itself, otherwise if we XOR a number even number of times with itself, the result is 0. Also XOR with 0 is always the number itself.

XOR x with 0
x ^ 0 = x
 
XOR x with itself even number of times
x ^ x = 0
x ^ x ^ x ^ x = (x ^ x) ^ (x ^ x) = 0 ^ 0 = 0
 
XOR x with itself odd number of times
(x ^ x ^ x) = (x ^ (x ^ x)) = (x ^ 0) = x
(x ^ x ^ x ^ x ^ x) = (x ^ (x ^ x) ^ (x ^ x)) = (x ^ 0 ^ 0) = x

So, if we take XOR of all elements present in the array, even appearing elements will cancel each other and we are left with the only odd appearing element.

*/

// Function to find odd occurring element in a given array
int findOddOccuring(int arr[], int n)
{
	int xor = 0;
	for (int i = 0; i < n; i++)
		xor = xor ^ arr[i];

	return xor;
}

// main function
int main()
{
	int arr[] = { 4, 3, 6, 2, 6, 4, 2, 3, 4, 3, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Odd occurring element is %d", findOddOccuring(arr, n));

	return 0;
}