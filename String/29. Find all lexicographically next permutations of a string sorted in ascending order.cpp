#include <bits/stdc++.h>
using namespace std;

// Function to find lexicographically previous permutations of a
// string. It returns true if the string could be rearranged as
// a lexicographicaly smaller permutation else it returns false
bool prev_permutation(string &str, int n)
{
    // Find largest index i such that str[i] is less than str[i - 1]
    int i = n - 1;
    while (str[i - 1] <= str[i])
    {
    	// if i is first index of the string, that means we are already at
    	// lowest possible permutation i.e. string is sorted in asc order
    	if (--i == 0)
        	return false;
    }

 	// if we reach here, substring str[i..n) is sorted in ascending order
	// i.e. str[i-1] > str[i] <= str[i+1] <= str[i+2] <= ... <= str[n-1]

    // Find a index j to the right of index i such that str[j] > str[i–1]
    int j = i + 1;
    while (j < n && str[j] <= str[i-1])
        j++;

    // Swap characters at index i-1 with index j-1
    swap(str[i-1], str[j-1]);

    // Reverse the substring str[i..n) and return true
    reverse(str.begin() + i, str.end());

    return true;
}

// Function to find all lexicographically previous permutations of a
// string sorted in descending order
void permutations(string str)
{
	// sort the string in descending order
	sort(str.rbegin(), str.rend());	// using reverse iterator

	while(1)
	{
		// print the current permutation
		cout << str << " ";

		// find previous lexicographically ordered permutation
	 	if (!prev_permutation(str, str.length()))
	 		break;
	}
}

// main function
int main()
{
	string str = "BADC";

	permutations(str);

	return 0;
}
