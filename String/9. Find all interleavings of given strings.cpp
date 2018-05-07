#include <iostream>
#include <unordered_set>
using namespace std;

// Function to find all interleaving of string X and Y
void interleavings(string res, string X, string Y, auto &list)
{
	// insert res into set if we have reached end of both strings
	if (!X.length() && !Y.length())
	{
		list.insert(res);
		return;
	}

	// if string X is not empty, append its first character in the 
	// result and recuse for remaining substring
	if (X.length())
		interleavings(res + X[0], X.substr(1), Y, list);
	
	// if string Y is not empty, append its first character in the 
	// result and recuse for remaining substring
	if (Y.length())
		interleavings(res + Y[0], X, Y.substr(1), list);
}

int main()
{
	string X = "ABC";
	string Y = "ACB";

	// use set to handle duplicates
	unordered_set<string> list;
	
	interleavings("", X, Y, list);
	
	for (string res: list)
		cout << res << endl;
	
}