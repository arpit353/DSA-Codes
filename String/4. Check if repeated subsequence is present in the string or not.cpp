#include <bits/stdc++.h>
using namespace std;

// Recursive function to check if str[low..high] is a palindrome or not
bool isPalindrome(string str, int low, int high)
{
	// base case
	if (low >= high)
		return true;

    return (str[low] == str[high]) && isPalindrome(str, low + 1, high - 1);
}

// Function to checks if repeated subsequence is present
// in the string
bool repeatedSubsequence(string str)
{
	// map to store frequency of each distinct character 
	// of given string
    map<char, int> freq;
    
    // update map with frequency
    for (int i = 0; i < str.length(); i++)
    	// if frequency of any character becomes 3, 
    	// we have found the repeated subsequence
        if (++freq[str[i]] >= 3)
            return true;

    string temp;
    
    // consider all repeated elements (frequency 2 or more)
    // and discard all non-repeating elements (frequency 1)
    for (int i = 0; i < str.length(); i++)
        if (freq[str[i]] >= 2)
            temp += str[i];
	
	// return false if temp is a Palindrome
    return !isPalindrome(temp, 0, temp.length() - 1);
}

int main()
{
    string str = "XYBYAXB";		// XB is repeated subsequence
 
    if (repeatedSubsequence(str))
        cout << "Repeated Subsequence present";
    else
        cout << "No Repeated Subsequence";
 
    return 0;
}