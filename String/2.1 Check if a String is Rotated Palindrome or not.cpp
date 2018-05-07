#include <iostream>
#include <algorithm>
using namespace std;

/*

Given a string, check if it is a rotated palindrome or not.

For example,
 
CBAABCD is a rotated palindrome as it is rotation of palindrome ABCDCBA
BAABCC is a rotated palindrome as it is rotation of palindrome ABCCBA

*/

// Recursive function to check if str[low..high] is a palindrome or not
bool isPalindrome(string str, int low, int high)
{
	return (low >= high) || (str[low] == str[high] && 
				isPalindrome(str, low + 1, high - 1));
}

// Function to check if given string is a rotated palindrome or not
bool isRotatedPalindrome(string str)
{
	// length of given string	
	int m = str.length();
	
	// check for all rotations of the given string if it
	// is palindrome or not
	for (int i = 0; i < m; i++)
	{
		// in-place rotate the string by 1 unit
		rotate(str.begin(), str.begin() + 1, str.end());
		// rotate(str.rbegin(), str.rbegin()+1, str.rend());
		
		// return true if the rotation is a palindrome
		if (isPalindrome(str, 0, m - 1))
			return true;
	}

	// return false if no rotation is a palindrome
	return false;
}

int main() 
{
	// palindromic string
	string str = "ABCDCBA";

	// rotate it by 3 units
	rotate(str.begin(), str.begin() + 2, str.end());

	if (isRotatedPalindrome(str))
		cout << "Given string is a rotated palindrome";
	else 
		cout << "Given string is not a rotated palindrome";

	return 0;
}
