#include <iostream>
#include <algorithm>
using namespace std;

/*

Given a string, check if it is a rotated palindrome or not.

For example,
 
CBAABCD is a rotated palindrome as it is rotation of palindrome ABCDCBA
BAABCC is a rotated palindrome as it is rotation of palindrome ABCCBA

*/

// expand in both directions of low and high to find 
// palindrome of length k
bool expand(string str, int low, int high, int k)
{
    while (low >= 0 && high < str.length() && (str[low] == str[high]))
    {
    	// return true palindrome of length k is found
    	if (high - low + 1 == k)
    		return true;

		// expand in both directions
    	low--, high++;
    }

    // return false if palindrome of length k is not found
    return false;
}

// Function to check if palindromic substring of length k exists or not
bool LongestPalindromicSubstring(string str, int k)
{
    for (int i = 0; i < str.length() - 1; i++)
    	// check if odd length or even length palindrome of length k
    	// having str[i] as its mid point exists
        if (expand(str, i, i, k) || expand(str, i, i + 1, k))
			return true;
    
    return false;
}

// Function to check if given string is a rotated palindrome or not
bool isRotatedPalindrome(string str)
{
	// length of given string
	int m = str.length();
	
	// return true if longest palindromic substring of length m
	// exists in the string (str + str)
	return LongestPalindromicSubstring(str + str, m);
}

int main()
{
	// palindromic string
	string str = "ABCCBA";

	// rotate it by 2 units
	rotate(str.begin(), str.begin() + 2, str.end());
	
	if (isRotatedPalindrome(str))
		cout << "Given string is a rotated palindrome";
	else 
		cout << "Given string is not a rotated palindrome";

	return 0;
}
