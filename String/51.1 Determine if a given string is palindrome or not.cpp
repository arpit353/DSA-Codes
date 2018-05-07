#include <iostream>
using namespace std;

// Iterative function to check if given string is a palindrome or not
bool isPalindrome(string str)
{
	int low = 0;
	int high = str.length() - 1;
	
	while (low < high)
	{
		// if mismatch happens
		if (str[low] != str[high])
			return false;

		low++;
		high--;
	}
	
	return true;
}

// main function
int main()
{
	string str = "XYXYX";

	if (isPalindrome(str))
		cout << "Palindrome";
	else
		cout << "Not Palindrome";
 
	return 0;
}