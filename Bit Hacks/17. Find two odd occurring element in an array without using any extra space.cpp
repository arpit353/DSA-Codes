#include <iostream>
#include <math.h>
using namespace std;

/*

Given an array of integers, duplicates appear in it even number of times except two elements which appears odd number of times. Find both odd appearing element without using any extra memory.
Expected time complexity: O(n)

For example,

Input:  arr = [4, 3, 6, 2, 4, 2, 3, 4, 3, 3]

Output: Odd occurring element are 4 and 6

4 appears 3 times
3 appears 4 times
6 appears 1 times
2 appears 2 times

*/

/*

Take XOR of both the numbers. Then get its rightmost bit. Then traverse the array. All those who have that bit set are XORed with x and other are XORed with Y. SInce every other element comes even number of times they will cancel out each other and these 2 numbers will only left.


We can solve this problem in O(1) space by using XOR operator. We know that if we XOR a number with itself odd number of times the result is number itself, otherwise if we XOR a number even number of times with itself, the result is 0. Also XOR with 0 is always the number itself.

XOR x with 0
x ^ 0 = x
 
XOR x with itself even number of times
x ^ x = 0
x ^ x ^ x ^ x = (x ^ x) ^ (x ^ x) = 0 ^ 0 = 0
 
XOR x with itself odd number of times
(x ^ x ^ x) = (x ^ (x ^ x)) = (x ^ 0) = x
(x ^ x ^ x ^ x ^ x) = (x ^ (x ^ x) ^ (x ^ x)) = (x ^ 0 ^ 0) = x

So, if we take XOR of all elements present in the array, even appearing elements will cancel out each other and we are left with XOR of x and y (x ^ y) where x and y are two odd appearing elements.
 
How to find x and y?
 
Let res = (x ^ y)

We know that any set bit in res will be either set in x or y (but not in both as a bit will only set in res when it is set in one number and unset in the other).

The idea is to consider the rightmost set bit in res (or any other set bit) and split the array into two sub-arrays –

All elements that have this bit set.
All elements that have this bit unset.
As this rightmost bit is set in one number and unset in the other, we will have one odd appearing element in each sub-array. Basically we have isolated trait of one number with other so that both x and y will go to different sub-array.

Now we iterate each sub-array once more, do XOR on each element of the sub-array and the result will be the odd appearing element present in the sub-array (since even appearing elements will cancel each other).

*/


pair<int, int> findOddOccuring(int arr[], int n)
{
	int res = 0;
	
	// take XOR of all array elements
	for (int i = 0; i < n; i++)
		res = res ^ arr[i];
	
	// find position of the rightmost set bit in res
	int k = log2(res & -res);
	
	// x and y are two odd appearing elements
	int x = 0, y = 0;
	
	// split the array into two sub-arrays
	for (int i = 0; i < n; i++)
	{
		// elements that have k'th bit set
		if (arr[i] & (1 << k))
			x = x ^ arr[i];

		// elements that don't have k'th bit set
		else
			y = y ^ arr[i];
	}

	return make_pair(x, y);
}

int main()
{
	int arr[] = { 4, 3, 6, 2, 4, 2, 3, 4, 3, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	pair<int, int> p = findOddOccuring(arr, n);
	cout << "Odd occurring element are " << p.first << " and " << p.second;

	return 0;
}
