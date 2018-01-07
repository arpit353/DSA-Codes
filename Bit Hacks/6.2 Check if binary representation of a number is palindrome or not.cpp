#include <iostream>
using namespace std;

/*

For example, 101, 11, 11011, 1001001 are palindromes. 100, 110, 1011, etc are not palindromes.
The idea is to construct reverse of binary representation of n and return true if it is same as n.

For constructing the reverse we will shift left one bit so that rightmost bit become 0. Then we will OR it with the current last bit of the K. So The digits of K which are as back as possible in K are coming in front in rev as they are pushed earlier.

*/

// return true if binary representation of n is a palindrome
bool isPalindrome(unsigned n)
{
	// rev stores reverse of binary representation of n
	unsigned rev = 0;
	
	// do till all bits of n are processed
	unsigned k = n;
	while (k)
	{
		// add rightmost bit to rev 
		rev = (rev << 1) | (k & 1);
		k = k >> 1;		// drop last bit
	}

	// return true if reverse(n) is same as n
	return n == rev;
}

int main() 
{
	int n = 9;	// 1001

	if (isPalindrome(n))
		cout << n << " is Palindrome";
	else
		cout << n << " is not a Palindrome";


	return 0;
}