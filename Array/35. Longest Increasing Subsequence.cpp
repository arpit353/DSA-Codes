#include <bits/stdc++.h>
using namespace std;

/*

Let S[i] be defined as the smallest integer that ends an increasing sequence of length i. Now iterate through every integer X of the input set and do the following:

If X is more than the last element in S, then append X to the end of S. This essentially means we have found a new largest LIS.
 
Otherwise find the smallest element in S, which is more than or equal to X, and replace it with X. Because S is sorted at any time, the element can be found using binary search in log(N) time.
Let’s illustrate this with the help of a example. Consider below array of integers –

    {2, 6, 3, 4, 1, 2, 9, 5, 8}

Below are the steps followed by the algorithm –

Initialize to an empty set S = {}
Inserting 2 —- S = {2} – New largest LIS
Inserting 6 —- S = {2, 6} – New largest LIS
Inserting 3 —- S = {2, 3} – Replaced 6 with 3
Inserting 4 —- S = {2, 3, 4} – New largest LIS
Inserting 1 —- S = {1, 3, 4} – Replaced 2 with 1
Inserting 2 —- S = {1, 2, 4} – Replaced 3 with 2
Inserting 9 —- S = {1, 2, 4, 9} – New largest LIS
Inserting 5 —- S = {1, 2, 4, 5} – Replaced 9 with 5
Inserting 8 —- S = {1, 2, 4, 5, 8} – New largest LIS

 

So, the length of the LIS is 5 (the size of S). Please note that here S[i] is defined as the smallest integer that ends an increasing sequence of length i. Therefore, S does not represent an actual sequence but the size of S represents the length of the LIS.

Below solution uses std::set which is implemented as a red-black binary search tree which has a worst-case time complexity of O(logn) for insertion.

*/

// Function to find length of Longest Increasing Subsequence in given array
int findLISLength(int arr[], int n)
{
	// create an empty ordered set S. ith element in S is defined as the 
	// smallest integer that ends an increasing sequence of length i
	set<int> S;

	// process every element one by one
	for (int i = 0; i < n; i++)
	{
		// insert current element into the set
		auto ret = S.insert(arr[i]);

		// get iterator to inserted element's
		set<int>::iterator it;
		if (ret.second)
			it = ret.first;

		// if element is not inserted at the end, then delete next
		// greater element from set
		if (++it != S.end())
			S.erase(it);

		// uncomment below code to print contents of the set after
		// every insertion
		/*
		cout << "\nInserting " << arr[i] << ": ";
		for (auto i: S)
			cout << i << " "; */
	}

	// length of LIS is number of elements in the set	
	return S.size();
}

// main function
int main()
{
	int arr[] = { 2, 6, 3, 4, 1, 2, 9, 5, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Length of LIS is " << findLISLength(arr, n) << endl;

	return 0;
}