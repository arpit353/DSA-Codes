#include <iostream>
using namespace std;

// Recursive function to check if str[low..high] is a palindrome or not
bool isPalindrome(string str, int low, int high)
{
	return (low >= high) || (str[low] == str[high] && 
							isPalindrome(str, low + 1, high - 1));
}

// main function
int main()
{
	string str = "XYBYBYX";
 	int len = str.length();

	if (isPalindrome(str, 0, len - 1))
		cout << "Palindrome";
	else
		cout << "Not Palindrome";
 
	return 0;
}