#include <iostream>
using namespace std;

/*

Given a string, find maximum-length contiguous substring of it that is also a palindrome. For example, the longest palindromic substring of “bananas” is “anana” and longest palindromic substring of “abdcbcdbdcbbc” is “bdcbcdb”.

Note that the longest palindromic substring is not guaranteed to be unique. For example, in the string “abracadabra”, there is no palindromic substring with length greater than three, but there are two palindromic substrings with length three, namely, “aca” and “ada”. If multiple longest palindromic substring exists, return any one of them.

*/

// expand in both directions of low and high to find 
// maximum length palindrome
string expand(string str, int low, int high)
{
	int len = str.length();

	// expand in both directions
	while (low >= 0 && high < len && (str[low] == str[high]))
		low--, high++;

	// return palindromic substring
	return str.substr(low + 1, high - low - 1);
}

// Function to find Longest Palindromic Substring in O(n^2) time 
// and O(1) space
string LongestPalindromicSubstring(string str, int len)
{	
	// max_str stores the maximum length palindromic substring 
	// found so far
	string max_str = "", curr_str;
	
	// max_length stores the length of maximum length palindromic substring 
	// found so far
	int max_length = 0, curr_length;	
	
	// consider every adjacent pair of characters as mid points and
	// expand in both directions to find maximum length palindrome 
	for (int i = 0; i < len; i++) 
	{
		// find a longest odd length palindrome with str[i] as mid point
		curr_str = expand(str, i, i);
		curr_length = curr_str.length();
		
		// update maximum length palindromic substring if odd length
		// palindrome has greater length
		if (curr_length > max_length)
		{
			max_length = curr_length;
			max_str = curr_str;
		}

		// find a longest even length palindrome with str[i] and str[i+1] as
		// mid points. Note that an even length palindrome has two mid points	
		curr_str = expand(str, i, i + 1);
		curr_length = curr_str.length();
		
		// update maximum length palindromic substring if even length 
		// palindrome has greater length
		if (curr_length > max_length)
		{
			max_length = curr_length;
			max_str = curr_str;
		}
	}
	
	return max_str;
}

int main()
{
	string str = "ABDCBCDBDCBBC";

	cout << "Longest Palindromic Substring of " << str << " is " 
			<< LongestPalindromicSubstring(str, str.length() - 1);

	return 0;
}