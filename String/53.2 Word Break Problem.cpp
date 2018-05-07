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


// Function to determine if string can be segmented into a space-separated 
// sequence of one or more dictionary words
bool wordBreak(vector<string> dict, string str)
{
	// return true if we have reached the end of the string, 
	if (str.size() == 0)
		return true;
	
    for (int i = 1; i <= str.size(); i++) 
    {
		// consider all prefixes of current string
        string prefix = str.substr(0, i);

		// return true if prefix is present in the dictionary and remaining
		// string also forms space-separated sequence of one or more
		// dictionary words
		if (find(dict.begin(), dict.end(), prefix) != dict.end() && 
            	wordBreak(dict, str.substr(i)))
        	return true;
    }
    
    // return false if the string can't be segmented
    return false;
}

// main function
int main()
{
	// vector of strings to represent dictionary	
    vector<string> dict = { "this", "th", "is", "famous", "Word", "break", "b",
					"r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };

	// input string
	string str = "Wordbreakproblem";
    
    if (wordBreak(dict, str))
    	cout << "String can be segmented";
	else
		cout << "String can't be segmented";

    return 0;
}
