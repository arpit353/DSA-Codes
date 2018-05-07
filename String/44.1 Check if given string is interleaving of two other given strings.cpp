#include <iostream>
using namespace std;

// Function to check if string X and Y are interleaving of
// string S or not
bool interleaved(string X, string Y, string S)
{
	// return true if we have reached end of all strings
	if (!X.length() && !Y.length() && !S.length())
		return true;

	// return false if we have reached the end of String S 
	// but string X or Y are not empty
	if (!S.length())
		return false;
	
	// if string X is not empty and its first character matches with
	// first character of S, recuse for remaining substring
	bool x = (X.length() && S[0] == X[0]) && 
			interleaved(X.substr(1), Y, S.substr(1));

	// if string Y is not empty and its first character matches with
	// first character of S, recuse for remaining substring	
	bool y = (Y.length() && S[0] == Y[0]) && 
			interleaved(X, Y.substr(1), S.substr(1));

	return x || y;
}

int main()
{
	string X = "ABC";
	string Y = "ACD";
	string S = "ACDABC";

	if (interleaved(X, Y, S))
		cout << "Given string is interleaving of X and Y";
	else
		cout << "Given string is not an interleaving of X and Y";
	
	return 0;
}