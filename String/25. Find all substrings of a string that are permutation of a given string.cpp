#include <bits/stdc++.h>
using namespace std;

// Function to find all substrings of string X that are
// permutations of string Y
void findAllAnagrams(string X, string Y)
{
	// m and n stores size of string Y and X respectively
	int m, n;

	// invalid input
	if ((m = Y.length()) > (n = X.length()))
		return;

	// maintains count of characters in current window
	unordered_multiset<char> window;

	// maintains count of characters in second string	
	unordered_multiset<char> set;

	// insert all characters of string Y into set
	for (int i = 0; i < m; i++)
		set.insert(Y[i]);

	// Note that std::unordered_multiset or std::multiset can maintain
	// duplicate elements unlike std::unordered_set or std::set
	
	// maintain a sliding window of size m with adjacent characters 
	// of string X 
	for (int i = 0; i < n; i++) 
	{
		// add first m characters of string X into current window
		if (i < m)
			window.insert(X[i]);
		
		else
		{
			// If all characters in current window matches that of
			// string Y, we found an anagram
			if (window == set) 
			{
				cout << "Anagram " << X.substr(i - m, m) << 
					" present at index " << i - m << endl;
			}
			
			// consider next substring of X by removing leftmost element of
			// the sliding window and add next character of string X to it
		
			// delete only "one" occurrence of leftmost element of
			// current window
			auto itr = window.find(X[i - m]);
			if (itr != window.end())
				window.erase(itr);

			// insert next character of string X in current window
			window.insert(X[i]);
		}
	}
	
	// if last m characters of string X matches that of string Y, 
	// we found an anagram
	if (window == set)
	{
		cout << "Anagram " << X.substr(n - m, m) << 
			" present at index " << n - m << endl;
	}
}

// main function
int main()
{
	string X = "XYYZXZYZXXYZ";
	string Y = "XYZ";

	findAllAnagrams(X, Y);

	return 0;
}