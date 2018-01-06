#include <iostream>
using namespace std;

// Function to find a duplicate element in a limited range array
int findDuplicate(int arr[], int n)
{
    // create an visited array of size n
    // we can also use map instead of visited array
	bool visited[n];
	fill(visited, visited + n, 0); // sets every value in the array to 0

	// for each element of the array mark it as visited and
	// return the element if it is seen before
	for (int i = 0; i < n; i++)
    {
        // if element is seen before
		if (visited[arr[i]])
			return arr[i];

        // mark element as visited
        visited[arr[i]] = true;
	}

	// no duplicate found
	return -1;
}

// main function
int main()
{
    // input array contains n numbers between [1 to n - 1]
    // with one duplicate
	int arr[] = { 1, 2, 3, 4, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Duplicate element is " << findDuplicate(arr, n);

	return 0;
}
