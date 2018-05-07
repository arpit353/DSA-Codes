#include <bits/stdc++.h>
using namespace std;

// Function to group anagrams together from given 
// list of words
void groupAnagrams(string words[], int n)
{
	// construct a vector out of given words and sort each word
	vector<string> list(words, words + n);
	for (string &s: list)		// don't forget to put &
		sort(s.begin(), s.end());
	
	// construct a map where key is each sorted word 
	// and value is list of indexes where it is present
	unordered_map<string, vector<int>> map;
	for (int i = 0; i < n; i++)
		map[list[i]].push_back(i);

	// traverse the map and read indexes for each sorted key.
	// The anagrams are present in actual list at those indexes
	for (auto itr : map) 
	{
		for (int index : itr.second)
			cout << words[index] << " ";
		cout << endl;
	}
}

int main()
{
	// list of words
	string words[] = 
	{
		"CARS", "REPAID", "DUES", "NOSE", "SIGNED", "LANE", "PAIRED", "ARCS", 
		"GRAB", "USED", "ONES", "BRAG", "SUED", "LEAN", "SCAR", "DESIGN"
	};

	// size of list
	int n = sizeof(words) / sizeof(words[0]);

	groupAnagrams(words, n);
	
	return 0;
}
