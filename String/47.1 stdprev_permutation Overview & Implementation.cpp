#include <iostream>
#include <algorithm>

// Program to find lexicographically smaller permutations of a string
int main()
{
	std::string s = "231";
	
	/* Optional: sort the string in reverse order before calling
	 std::prev_permutation to print all permutations, not just the ones
	 that follows specified string lexicographically */

	// std::sort(rbegin(s), rend(s));

	// find all lexicographically smaller permutations using 
	// std::prev_permutation
	while (1)
	{
		// print current permutation
		std::cout << s << " ";

		// find previous permutation in lexicographic order
		if (!std::prev_permutation(begin(s), end(s)))
			break;
	}

	return 0;
}