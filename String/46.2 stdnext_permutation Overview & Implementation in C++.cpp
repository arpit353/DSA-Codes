#include <iostream>
#include <algorithm>

// Function to rearrange the specified string as lexicographically greater 
// permutation. It returns false if the string cannot be rearranged as
// lexicographically greater permutation, else it returns true
bool nextPermutation(std::string &s, int n)
{
	// Find largest index i such that s[i-1] is less than s[i]
	int i = n-1;
	while (s[i-1] >= s[i])
	{
		// Return false if i is at first index of the string
		// It means we are already at highest possible permutation
		if (--i == 0)
			return false;
	}

  	// If we reach here, substring s[i..n-1] is sorted in reverse order
	// Find highest index j to the right of index i such that s[j] > s[i–1]
	int j = n-1;
	while (j > i && s[j] <= s[i-1])
		j--;

	// Swap characters at index i-1 with index j
	std::swap(s[i-1], s[j]);

	// Reverse the substring s[i..n-1] and return true
	std::reverse (s.begin() + i, s.end());

	return true;
}

// Program to find all lexicographically greater permutations
int main()
{
	std::string s = "231";

	// std::sort(begin(s), end(s));

	// find all lexicographically greater permutations using 
	// std::next_permutation
	while (1)
	{
		// print current permutation
		std::cout << s << " ";

		// find next permutation in lexicographic order
	 	if (!nextPermutation(s, s.length()))
	 		break;
	}
	
	return 0;
}