#include <bits/stdc++.h>
using namespace std;

/*
Given a positive number N, find all combinations of 2*N elements such that every element from 1 to N appears exactly twice and distance between its two appearances is exactly equal to value of the element.
 
For example,

Input:  N = 3
Output:
3 1 2 1 3 2
2 3 1 2 1 3

Input:  N = 4
Output:
4 1 3 1 2 4 3 2
2 3 4 2 1 3 1 4

Input:  N = 7
Output:
1 7 1 2 5 6 2 3 4 7 5 3 6 4
5 1 7 1 6 2 5 4 2 3 7 6 4 3
4 1 7 1 6 4 2 5 3 2 7 6 3 5
…
…
Total 52 configurations possible

Note that no combination of elements is possible for some values of N like 2, 5, 6, etc.

We can use backtracking to solve this problem. The idea is to try all possible combinations for the first element and recursively explore remaining elements to check if they will lead to the solution or not. If current configuration doesn’t result in solution, we backtrack. Note that an element k can be placed at position i and (i+k+1) in the output array where i >= 0 and (i + k + 1) < 2*N.

*/

// Find all combinations that satisfies given constraints 
void findAllCombinations(vector<int> &arr, int elem, int n)
{
	// if all elements are filled, print the solution
	if (elem > n)
	{
		for (int i : arr)
			cout << i << " ";
		cout << endl;
		
		return;
	}

	// try all possible combinations for element elem
	for (int i = 0; i < 2*n; i++)
	{
		// if position i and (i+elem+1) are not occupied in the vector
		if (arr[i] == -1 && (i + elem + 1) < 2*n && 
			arr[i + elem + 1] == -1)
		{
			// place elem at position i and (i+elem+1)
			arr[i] = elem;
			arr[i + elem + 1] = elem;

			// recurse for next element
			findAllCombinations(arr, elem + 1, n);
			
			// backtrack (remove elem from position i and (i+elem+1) )
			arr[i] = -1;
			arr[i + elem + 1] = -1;
		}
	}
}

int main()
{
	// given number
	int n = 7;
	
	// create a vector of double the size of given number with
	// all its elements initialized by -1
	vector<int> arr(2*n, -1);

	// start from element 1
	int elem = 1;
	findAllCombinations(arr, elem, n);

	return 0;
}

/*

Output: 

1 7 1 2 5 6 2 3 4 7 5 3 6 4
1 7 1 2 6 4 2 5 3 7 4 6 3 5
1 6 1 7 2 4 5 2 6 3 4 7 5 3
1 5 1 6 7 2 4 5 2 3 6 4 7 3
1 4 1 5 6 7 4 2 3 5 2 6 3 7
1 4 1 6 7 3 4 5 2 3 6 2 7 5
1 6 1 3 5 7 4 3 6 2 5 4 2 7
1 5 1 7 3 4 6 5 3 2 4 7 2 6
1 5 1 6 3 7 4 5 3 2 6 4 2 7
1 5 1 4 6 7 3 5 4 2 3 6 2 7
5 1 7 1 6 2 5 4 2 3 7 6 4 3
4 1 7 1 6 4 2 5 3 2 7 6 3 5
…
…

*/