#include <bits/stdc++.h>
using namespace std;

// Utility function to print contents of the vector
void printVector(vector<auto> out)
{
	for (auto str: out)
		cout << str << " ";

	cout << endl;
}

// Find all combinations of non-overlapping substrings of given string
void recurse(string str, vector<string> &out)
{
    // if all characters of the input string are processed,
    // print the output string
	if (str.length() == 0)
	{
		printVector(out);
		return;
	}

	// add each substring [0, i] in the output vector and recuse for 
	// remaining substring [i+1, n-1]
	for (int i = 0; i < str.length(); i++)
	{
	    // push substring [0, i] into output vector
		out.push_back("(" + str.substr(0, i + 1) + ")");

		// recuse for remaining string [i+1, n-1]
		recurse(str.substr(i + 1), out);

		// backtrack (remove current substring from vector)
		out.pop_back();
	}
}

// main function
int main()
{
	// input string
	string str = "ABCD";

	// output vector to store non-overlapping substrings
	vector<string> out;
	
	// Print all non-overlapping substrings
	recurse(str, out);

	return 0;
}
