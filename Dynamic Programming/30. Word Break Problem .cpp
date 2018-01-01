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

/*

In this code we are simply checking every subset of the word and check if the remaining word is present in the dictonary. if not present we again divide by passing it through the word break function. 

*/

#include <bits/stdc++.h> 
using namespace std;
 
#define N 50
 
int lookup[N+1] = {-1};
 
bool wordBreak(vector<string> dict, string str)
{
    int n = str.size();
 
    if (n == 0)
        return true;
 
    if (lookup[n] == -1)
    {
        lookup[n] = 0;
    
        for (int i = 1; i <= n; i++) 
        {
            string prefix = str.substr(0, i);
    
            if (find(dict.begin(), dict.end(), prefix) != dict.end() && 
                wordBreak(dict, str.substr(i)))
            {
                return lookup[n] = 1;
            }
        }
    }
 
    return lookup[n];
}
 
int main()
{
    vector<string> dict = { "this", "th", "is", "famous", "Word", "break", 
            "b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };
 
    string str = "Wordbreakproblem";
    
    memset(lookup, -1, sizeof(lookup));
 
    if (wordBreak(dict, str))
        cout << "String can be segmented";
    else
        cout << "String can't be segmented";
 
    return 0;
}


