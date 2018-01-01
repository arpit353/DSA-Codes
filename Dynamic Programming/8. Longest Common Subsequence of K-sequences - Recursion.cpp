#include <bits/stdc++.h>
using namespace std;

/*

This code is nothing but same code for 2 strings is extended for k strigs . Here k is 3. 
if last letter is same we add 1 other wise we recusively find the maximum lcs we got from the 3 strings.

*/

int max(int a, int b, int c)
{
	return max(max(a, b), c);
}

int LCSLength(string X, string Y, string Z, int m, int n, int o, auto &lookup)
{
	if (m == 0 || n == 0 || o == 0)
		return 0;

	string key = to_string(m) + "|" + to_string(n) + "|" + to_string(o);
 
	if (lookup.find(key) == lookup.end())
	{
		if (X[m - 1] == Y[n - 1] && Y[n - 1] == Z[o - 1])
			lookup[key] = LCSLength(X, Y, Z, m - 1, n - 1, o - 1, lookup) + 1;
		else
			lookup[key] = max(LCSLength(X, Y, Z, m - 1, n, o, lookup), 
							LCSLength(X, Y, Z, m, n - 1, o, lookup),
							LCSLength(X, Y, Z, m, n, o - 1, lookup));
	}
	return lookup[key];
}
 
int main()
{
	string X = "ABCBDAB", Y = "BDCABA", Z = "BADACB";

	unordered_map<string, int> lookup;

	cout << "The length of LCS is " << 
			LCSLength(X, Y, Z, X.length(), Y.length(), Z.length(), lookup);

	return 0;
}