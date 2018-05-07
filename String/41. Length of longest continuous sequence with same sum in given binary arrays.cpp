#include<bits/stdc++.h>
using namespace std;

// Given two boolean arrays X and Y, find the length of longest continuous sequence
// that starts and ends at same index in both arrays and have same sum
int findMaxSubarrayLength(bool X[], bool Y[], int n)
{
	// create an empty map
	unordered_map<int, int> map;

	// to handle the case when required sequence starts from index 0
	map[0] = -1;

	// stores length of longest continuous sequence
	int res = 0;

	// sum_x, sum_y stores sum of elements of X[] and Y[] respectively
	// till current index
	int sum_x = 0, sum_y = 0;

	// traverse both lists simultaneously
	for (int i = 0; i < n; i++)
	{
		// update sum_x and sum_y
		sum_x += X[i];
		sum_y += Y[i];

		// calculate difference between sum of elements in two lists
		int diff = sum_x - sum_y;

		// if difference is seen for the first time, then store the
		// difference and current index in a map
		if (map.find(diff) == map.end())
			map[diff] = i;

		// if difference is seen before, then update the result
		else
			res = max(res, i - map[diff]);
	}

	return res;
}

// main function
int main()
{
	bool X[] = {0, 0, 1, 1, 1, 1};
	bool Y[] = {0, 1, 1, 0, 1, 0};

	int n = sizeof(X)/sizeof(X[0]);

	cout << "The length of longest continuous sequence with same sum is " << 
			findMaxSubarrayLength(X, Y, n);

	return 0;
}
