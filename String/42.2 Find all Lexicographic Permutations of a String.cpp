#include <bits/stdc++.h>
using namespace std;

// Function to find all lexicographic permutations of given 
// string where repetition of characters is allowed
void Lexicographic (string str, string res)
{
	// base condition (permutation found)
	if (res.length() == str.length())
	{
		// print the permutation and return
		cout << res << " ";
		return;
	}
	
	// consider all characters of the string one by one
	for (int i = 0; i < str.length(); i++)
	{
	    // skip adjacent duplicates
	    while (i + 1 < str.length() && str[i] == str[i + 1])
	        i++;
	   
	    Lexicographic (str, res + str[i]);
	}
	
	// above for loop can be replaced by below for loop	
	/* for (int i = 0; i < str.length(); i++ )
	{
    	while (i + 1 < str.length() && str[i] == str[i + 1])
	        i++;
	        
		res.push_back(str[i]);
		Lexicographic (str, res);
		res.pop_back();		// backtrack
	}*/
}

// main function
int main()
{
	string str = "AAB";
	
	string res;
	
	// sort the string to print in lexicographical order
	sort(str.begin(), str.end());

	Lexicographic(str, res);
	
	return 0;
}
