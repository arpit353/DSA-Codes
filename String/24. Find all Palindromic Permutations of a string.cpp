#include <bits/stdc++.h>
using namespace std;

// Function to find all palindrome permutations of given string
void palindromicPermutations(string str)
{
	// store frequency of each character of string in a map
	unordered_map<char, int> freq;
	for (char ch: str)
		freq[ch]++;
	
	int odd = 0;		// stores odd character's count
	string mid;			// stores odd character
	string left, right;	// stores left and right half
	
	// iterate through the map
	for (auto itr: freq)
	{
		char ch = itr.first;	// current character
		int c = itr.second;		// character count
		
		if ((c & 1))			// if count of current character is odd
		{
			// if more than one odd character is present in the string
			// palindrome permutations is not possible
			if (++odd > 1)
				return;
			
			c = c - 1;			// make count even or 0	
			mid = itr.first;	// update mid
		}
		
		// append c/2 characters to the left half
		// (other c/2 characters will go in right half)
		c = c/2;
		while (c--)
			left = left + ch;		// update left
	}

	// sort left half to generate permutations in lexicographical order
	// no need to sort if we use std::map as keys are already sorted
	sort(left.begin(), left.end());
	
	while (1)
	{
		// right half will be reverse of left half
		right = left;
    	reverse(right.begin(), right.end());
    	
    	// print left half, mid character (if any) and right half
		cout << (left + mid + right) << endl;
        
        // find next lexicographically greater permutation
	 	if (!next_permutation(left.begin(), left.end()))
	 		break;
	}
	// Note - we can also sort in reverse order and use std::prev_permutation
}

// main function
int main() 
{
	string str = "xyxzwxxyz";
    
    palindromicPermutations(str);
    
	return 0;
}