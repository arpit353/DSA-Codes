#include <iostream>
#include <algorithm>

// Program to find all lexicographically next permutations
int main()
{
	std::string s = "231";
	
	// Optional: sort the string in natural order before calling
	// std::next_permutation inside a loop to print all permutations,
	// not just the ones that follows specified string lexicographically

	// std::sort(begin(s), end(s));

	// find all lexicographically next permutations using 
	// std::next_permutation
	while (1)
	{
		// print current permutation
		std::cout << s << " ";

		// find next permutation in lexicographic order
	 	if (!std::next_permutation(begin(s), end(s)))
	 		break;
	}

	return 0;
}