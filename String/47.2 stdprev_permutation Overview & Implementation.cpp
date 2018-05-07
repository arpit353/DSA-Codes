#include <iostream>
#include <algorithm>

// Function to rearrange the specified string as lexicographically smaller
// permutation. It returns false if the string cannot be rearranged as
// lexicographically smaller permutation, else it returns true
bool prevPermutation(std::string &s, int n)
{
	// Find largest index i such that s[i-1] is more than s[i]
	int i = n-1;
	while (i > 0 && s[i-1] <= s[i])
	{
		// Return false if i is at first index of the string
		// This means we're already at lowest possible permutation
		if (--i == 0)
			return false;
	}

	// s[i..n-1] is now sorted in natural order

	// Find highest index j such that j >= i and s[j] < s[i-1]
	int j = i;
	while (j < n && s[j] <= s[i-1])
		j++;

	j--;

	// Swap characters at index i-1 with index j
	std::swap(s[i-1], s[j]);

	// Reverse the substring s[i..n-1] and return true
	std::reverse (s.begin() + i, s.end());

	return true;
}

// Program to find lexicographically smaller permutations of a string
int main()
{
	std::string s = "231";

	// std::sort(rbegin(s), rend(s));

	// find all lexicographically smaller permutations using
	// std::prev_permutation
	while (1)
	{
		// print current permutation
		std::cout << s << " ";

		// find previous permutation in lexicographic order
	 	if (!prevPermutation(s, s.length()))
	 		break;
	}

	return 0;
}