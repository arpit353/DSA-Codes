#include <bits/stdc++.h>
using namespace std;


/*

The code is similar to the previous one the only diffference we are considering the orignal element also in recusion. See Game Point

*/

// Function to print the contents of the vector
void printVector(vector<int> out)
{
	for (auto it = out.begin(); it != out.end(); it++)
		cout << *it << " ";
	cout << endl;
}

// Function to print all distinct combinations of length k where 
// repetition of elements is allowed
void recurse(int arr[], vector<int> &out, int k, int i, int n)
{
    // base case: if combination size is k, print it
	if (out.size() == k)
	{
		printVector(out);
		return;
	}

	// start from previous element in the current combination till last element
	for (int j = i; j < n; j++)
	{
        // add current element arr[j] to the solution and recurse with
        // same index j (as repeated elements are allowed in combinations)
		out.push_back(arr[j]);
		recurse(arr, out, k, j, n); // Game Point

		// backtrack - remove current element from solution
		out.pop_back();

        // code to handle duplicates - skip adjacent duplicate elements
		while (arr[j] == arr[j + 1])
			j++;
	}
}

// main function
int main()
{
	int arr[] = { 1, 2, 1 };
	int k = 2;

	int n = sizeof(arr) / sizeof(arr[0]);

    // if array contains repeated elements, sort the array to
    // handle duplicates combinations
	sort (arr, arr + n);

	vector<int> out;
	recurse(arr, out, k, 0, n);

	return 0;
}
