#include <iostream>
#include <numeric>

/*
In k-partition problem, we need to partition an array of positive integers into k disjoint subsets that all have equal sum and they completely covers the set.

For example, consider below set
S = { 7, 3, 5, 12, 2, 1, 5, 3, 8, 4, 6, 4 }

1. S can be partitioned into 2 partitions each having sum 30.

S1 = { 5, 3, 8, 4, 6, 4 }
S2 = { 7, 3, 5, 12, 2, 1 }

2. S can be partitioned into 3 partitions each having sum 20.

S1 = { 2, 1, 3, 4, 6, 4 }
S2 = { 7, 5, 8 }
S3 = { 3, 5, 12 }

3. S can be partitioned into 4 partitions each having sum 15.

S1 = { 1, 4, 6, 4 }
S2 = { 2, 5, 8 }
S3 = { 12, 3 }
S4 = { 7, 3, 5 }

4. S can be partitioned into 5 partitions each having sum 12.

S1 = { 2, 6, 4 }
S2 = { 8, 4 }
S3 = { 3, 1, 5, 3 }
S4 = { 12 }
S5 = { 7, 5 }

k-partition problem is a special case of Partition Problem where the goal is to partition S into two subsets with equal sum. This post will extend the 3-partition solution to find and print k-partitions.

We can start by calculating the sum of all elements in the set. If sum is not divisible by k, we can’t divide the array into k subsets with equal sum. If sum is divisible by k, we check if k subsets with sum of elements equal to (sum/k) exists or not. We can find this by considering each item in the given array one by one and for each item we include it in the i’th subset & recurse for remaining items with remaining sum. We backtrack if solution is not found by including current item in i’th subset and try for (i+i)th subset.

We return true and print the subsets when k subsets each with zero sum are found. For printing the partitions, we maintain an separate array A[] to keep track of subsets elements. If the value of A[i] is k, then it means that i’th item of S is part of k’th subset.

*/


/*

Put the element in every subset and then check for next element. If in any case the elements fit in the given constarint. We print the subset.

*/

// Function to check if all subsets are filled or not
bool checkSum(int sumLeft[], int k)
{
	int r = true;
	for (int i = 0; i < k; i++)
	{
		if (sumLeft[i] != 0)
			r = false;
	}

	return r;
}

// Helper function for solving k partition problem
// It return true if there exists k subsets with given sum
bool subsetSum(int S[], int n, int sumLeft[], int A[], int k)
{
	// return true if subset is found
	if (checkSum(sumLeft, k))
		return true;

	// base case: no items left
	if (n < 0)
		return false;

	bool res = false;

	// consider current item S[n] and explore all possibilities
	// using backtracking
	for (int i = 0; i < k; i++)
	{
		if (!res && (sumLeft[i] - S[n]) >= 0)
		{
			// mark current element subset
			A[n] = i + 1;

			// add current item to i'th subset
			sumLeft[i] = sumLeft[i] - S[n];
			
			// recurse for remaining items
			res = subsetSum(S, n - 1, sumLeft, A, k);
			
			// backtrack - remove current item from i'th subset
			sumLeft[i] = sumLeft[i] + S[n];
		}
	}

	// return true if we get solution
	return res;
}

// Function for solving k-partition problem. It prints the subsets if
// set S[0..n-1] can be divided into k subsets with equal sum
void partition(int S[], int n, int k)
{
	// base case
	if (n < k)
	{
		std::cout << "k-Partition of set S is not Possible";
		return;
	}

	// get sum of all elements in the set
	int sum = std::accumulate(S, S + n, 0);

 	int A[n], sumLeft[k];
 
 	// create an array of size k for each subset and initialize it 
 	// by their expected sum i.e. sum/k
	for (int i = 0; i < k; i++)
		sumLeft[i] = sum/k;
	
	// return true if sum is divisible by k and the set S can
	// be divided into k subsets with equal sum
	bool res = !(sum % k) && subsetSum(S, n - 1, sumLeft, A, k);

	if (!res)
	{
		std::cout << "k-Partition of set S is not Possible";
		return;
	}

	// print all k-partitions
	for (int i = 0; i < k; i++)
	{
		std::cout << "Partition " << i << " is: ";
	   	for (int j = 0; j < n; j++)
	 		if (A[j] == i + 1)
	 			std::cout << S[j] << " ";
	 	std::cout << std::endl;
	}
}

// main function for k-partition problem
int main()
{
	// Input: set of integers
	int S[] = { 7, 3, 5, 12, 2, 1, 5, 3, 8, 4, 6, 4 };

	// number of items in S
	int n = sizeof(S) / sizeof(S[0]);
	int k = 5;

	partition(S, n, k);

	return 0;
}

/*

Output: 

Partition 0 is: 2 6 4
Partition 1 is: 8 4
Partition 2 is: 3 1 5 3
Partition 3 is: 12
Partition 4 is: 7 5

*/