#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

/*

Word Break Problem: Given a string and a dictionary of words, determine if string can be segmented into a space-separated sequence of one or more dictionary words.

For example,
Input:

1
2
3
4
dict[] = { "this", "th", "is", "famous", "Word", "break", "b",
        "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };
 
string = "Wordbreakproblem"

Output:

Word b r e a k problem
Word b r e ak problem
Word br e a k problem
Word br e ak problem
Word bre a k problem
Word bre ak problem
Word brea k problem
Word break problem

*/



// Function to segment given string into a space-separated 
// sequence of one or more dictionary words
void wordBreak(vector<string> dict, string str, string out)
{
	// if we have reached the end of the string, 
	// print the output string
	if (str.size() == 0)
	{
		cout << out << endl;
		return;
	}
	
    for (int i = 1; i <= str.size(); i++) 
    {
		// consider all prefixes of current string
        string prefix = str.substr(0, i);

		// if the prefix is present in the dictionary, add prefix to the 
		// output string and recuse for remaining string
        if (find(dict.begin(), dict.end(), prefix) != dict.end()) 
            wordBreak(dict, str.substr(i), out + " " + prefix);
    }
}

// main function
int main()
{
	// vector of strings to represent dictionary
    vector<string> dict = { "this", "th", "is", "famous", "Word", "break", "b",
					"r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };

	// input string
	string str = "Wordbreakproblem";
    
    wordBreak(dict, str, "");

    return 0;
}
