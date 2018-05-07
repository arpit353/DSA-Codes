#include <bits/stdc++.h>
using namespace std;

// Function to print all words that follows same order of 
// characters as given pattern
void patternMatch(vector<string> list, string pattern)
{
	// len stores length of the pattern
	int len = pattern.length();

	// check each word in given input list
	for (string word : list)
	{
		// map1 stores mapping from word to pattern
		// map2 stores mapping from pattern to word
		unordered_map<char, int> map1, map2;
		
		// proceed only when length of the pattern and word is same
		if (word.length() == len)
		{
			int i;
			
			// process each character in both word and pattern
			for (i = 0; i < len; i++)
			{
				char w = word[i];		// w stores current character of current word
				char p = pattern[i];	// p stores current character of the pattern

				/* check mapping from current word to given pattern */

				// if w is seen for the first time, store its mapping to p in map1
				if (map1.find(w) == map1.end())
					map1[w] = p;
				else
				// if w is seen before, its mapped character should be p
					if (map1[w] != p)
						break;
				
				/* check mapping from given pattern to current word */

				// if p is seen for the first time, store its mapping to w in map2
				if (map2.find(p) == map2.end())
					map2[p] = w;
				else
				// if p is seen before, its mapped character should be w
				if (map2[p] != w)
						break;
			}
			
			// if current word matches the pattern, print it 
			if (i == len)
				cout << word << endl ;
		}
	}
}

int main()
{
	// list of words
	vector<string> list = 
	{
		"leet", "abcd", "loot", "geek", "cool", "for", "peer", 
		"dear", "seed", "meet", "noon", "otto", "mess", "loss"
	};

	// given pattern
	string pattern = "moon";
 
	patternMatch(list, pattern);
 
	return 0;
}