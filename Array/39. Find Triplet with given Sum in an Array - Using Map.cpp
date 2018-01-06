#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

/* This code is similar to finding a given sum exist for 2 numbers we studied in in the start. The difference here is we are considering pair of elements and finding out weather the the remaining part of the sum exists in the map or not. Just relate it to that */

// Function to check if triplet exists in array with given sum
bool tripletExists(int arr[], int n, int sum)
{
    // create an empty map
	unordered_map<int, int> map;

    // sort the array in ascending order
	sort(arr, arr + n);

    // insert (element, index) pair in map for each element in the array
	for (int i = 0; i < n; i++)
		map[arr[i]] = i;

    // consider each element except last element
    for (int i = 0; i < n - 1; i++)
	{
	    // start from i'th element till last element
		for (int j = i + 1; j < n; j++)
		{
		    // remaining sum
			int val = sum - (arr[i] + arr[j]);

		    // if remaining sum is found, we have found a triplet
			if (map.find(val) != map.end())
			{
			    // if triplet don't overlap, return true
				if (map[val] != i && map[val] != j)
                    return true;
			}
		}
	}

    // return false if triplet don't exists
	return false;
}

// main function
int main()
{
	int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
	int sum = 6;

	int n = sizeof(arr) / sizeof(arr[0]);

    tripletExists(arr, n, sum) ? cout << "Triplet Exists":
                                cout << "Triplet Don't Exist";


	return 0;
}
