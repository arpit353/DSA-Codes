#include <bits/stdc++.h>
using namespace std;

// defines maximum length of pattern or input string
#define LEN 20

/*

Given a string and a pattern containing wildcard characters i.e. ‘*’ and ‘?’, where ‘?’ can match to any single character in input string and ‘*’ can match to any number of characters including zero characters, design an efficient algorithm to find if the pattern matches with the complete input string or not.
 
For example,

Input: string = “xyxzzxy”, pattern = “x***y”
Output: Match

Input: string = “xyxzzxy”, pattern = “x***x”
Output: No Match

Input: string = “xyxzzxy”, pattern = “x***x?”
Output: Match

Input: string = “xyxzzxy”, pattern = “*”
Output: Match

*/


// create a DP lookup table
int lookup[LEN][LEN];

// Function that matches input string with given wildcard pattern
bool isMatching(char str[], char pattern[], int n, int m)
{
	// If both input string and pattern reaches their end,
	// return true
	if (m < 0 && n < 0)
		return true;
	
	// If only pattern reaches its end, return false
	else if (m < 0)
		return false;
	
	// If only input string reaches its end, return true 
	// if remaining characters in the pattern are all '*'
	else if (n < 0) 
	{
		for (int i = 0; i <= m; i++)
			if (pattern[i] != '*')
				return false;

		return true;
	}
	
	// If the sub-problem is encountered for the first time
	if (lookup[m][n] == -1) 
	{
		if (pattern[m] == '*') 
		{
			// 1. * matches with current characters in input string. 
			// Here we will move to next character in the string
			
			// 2. Ignore * and move to next character in the pattern
			lookup[m][n] = isMatching(str, pattern, n - 1, m) || 
						isMatching(str, pattern, n, m - 1);
		}
		else 
		{
			// If the current character is not a wildcard character, it 
			// should match with current character in the input string
			if (pattern[m] != '?' && pattern[m] != str[n])
				lookup[m][n] = false;
			
			// check if pattern[0..m-1] matches str[0..n-1]
			else
				lookup[m][n] = isMatching(str, pattern, n - 1, m - 1);
		}
	}
	
	return lookup[m][n];
}

// main function
int main()
{
	char str[] = "xyxzzxy";
	char pattern[] = "x***x?";

	memset(lookup, -1, sizeof(lookup));

	if (isMatching(str, pattern, strlen(str) - 1, strlen(pattern) - 1))
		cout << "Match" << endl;
	else
		cout << "No Match" << endl;

	return 0;
}