#include <bits/stdc++.h>
using namespace std;

// Top-down Recursive function to find all possible combinations by
// replacing key's digits with characters of the corresponding list
void find(auto list, auto keys, string res, int index, auto map)
{
	// if we have processed every digit of key, print result
	if (index == -1)
	{
		cout << res << " ";
		return;
	}

	// stores current digit
	int digit = keys[index];
	
	// size of the list corresponding to current digit
	int len = list[digit].size();

	// if digit is seen for the first time
	if (map.find(digit) == map.end()) 
	{
		// one by one replace it with each character in the corresponding list
		// and recuse for next digit
		for (int i = 0; i < len; i++)
		{
			// store character that maps to the current digit in a map
			map[digit] = list[digit][i];
			
			// recuse for next digit
			find(list, keys, list[digit][i] + res, index - 1, map);
		}
		return;
	}
	
	// if digit is seen before, replace it with same character 
	// used in the previous occurrence
	find(list, keys, map[digit] + res, index - 1, map);
}

int main()
{
	// N lists of characters
	vector<char> list[] = 
	{
		{ 'A', 'B', 'C', 'D'},
		{ 'E', 'F', 'G', 'H', 'I', 'J', 'K' },
		{ 'L', 'M', 'N', 'O', 'P', 'Q' },
		{ 'R', 'S', 'T'},
		{ 'U', 'V', 'W', 'X', 'Y', 'Z' }
	};

	// input number in the form of an array
	int keys[] = {0, 2, 0};
	int n = sizeof(keys)/sizeof(keys[0]);

	// create an empty map to store the mapping of digits
	unordered_map<int, char> map;
	
	// find all combinations
	find(list, keys, "", n - 1, map);
	
	return 0;
}