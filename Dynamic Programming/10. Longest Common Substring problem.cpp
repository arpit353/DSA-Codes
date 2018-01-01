#include <bits/stdc++.h>
using namespace std;

/* 

The longest common substring problem is the problem of finding the longest string (or strings) that is a substring (or are substrings) of two strings.

*/

/*

In this we are just filling  a two by two matrix which shows the maximum length of string that match between the both of the string. That's why we only add 1 when both strings have same letter. 

Also we initialed the array as 0 for all elements because of that only.

*/

string LCS(string X, string Y, int m, int n)
{
	int maxlen = 0;			
	int endingIndex = m;	
	
	int lookup[m + 1][n + 1];

	memset(lookup, 0, sizeof(lookup));

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (X[i - 1] == Y[j - 1])
			{
				lookup[i][j] = lookup[i - 1][j - 1] + 1;
				
				if (lookup[i][j] > maxlen)
				{
					maxlen = lookup[i][j];
					endingIndex = i;
				}
			}
		}
	}
	
	return X.substr(endingIndex - maxlen, maxlen);
}

int main()
{
	string X = "ABC", Y = "BABA";
	int m = X.length(), n = Y.length();

	cout << "The Longest common substring is " << LCS(X, Y, m, n);

	return 0;
}
