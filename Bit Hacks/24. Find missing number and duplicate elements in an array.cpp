#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


/*

When we take the XOR of all the elements in the array and then take the XOR with natuarl numbers then The result we will get is XOR of duplicate and missing number because duplicate will be their for 3 times and missing will be their for 1 time. Then we seperate them from each other by taking the rightmost difference bit and then checking the all the array elemnt and natural numbers to make them zero and seperate as we discussed before also.  

*/

// Function to find the missing number and duplicate element 
// using XOR operator in an array of size n and range of 
// elements between [1 to n] 
pair<int, int> findMissingAndDuplicate(int arr[], int n)
{
	// take XOR of all array elements from index [0 to n-1] 
	// and all numbers in range [1 to n]
	int res = n;
	for (int i = 0; i < n; i++)
        res = res ^ arr[i] ^ i;

	// x, y stores the duplicate element and missing number
	int x = 0, y = 0;

    // res stores (x ^ y)

	// find position of the rightmost set bit in res
	int k = log2(res & -res);

	// split the array into two sub-arrays
	for (int i = 0; i < n; i++)
	{
		// array elements that have k'th bit 1
		if (arr[i] & (1 << k))
			x = x ^ arr[i];

		// array elements that have k'th bit 0
		else
			y = y ^ arr[i];
	}

	// split the range [1-n] into two sub-range
	for (int i = 1; i <= n; i++)
	{
		// number i have k'th bit 1
		if (i & (1 << k))
			x = x ^ i;

		// number i have k'th bit 0
		else
			y = y ^ i;
	}

	return make_pair(x, y);
}

int main()
{
	int arr[] = { 4, 3, 6, 5, 2, 4 };
	int n = 6;	// size of the array is n

	pair<int, int> p = findMissingAndDuplicate(arr, n);
	
	// linear search for missing element
	if (find(arr, arr + n, p.first) == arr + n)
		swap(p.first, p.second);
	
	cout << "Duplicate and missing elements are " 
			<< p.first << " and " << p.second;

	return 0;
}
