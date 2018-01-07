#include <iostream>
using namespace std;


/*

The given number n is power of 4 if it is power of 2 and its only set bit is present at even position (0, 2, 4, . . .).

How to check for power of 2?

The expression (n & (n – 1)) will unset the rightmost set bit of a number. If the number is power of 2, it has only one bit set and (n & (n – 1)) will unset the only set bit. So we can say that (n & (n – 1)) returns 0 if n is power of 2 else it is not a power of 2.

We can also the expression (n & -n) == n to check if a positive integer is a power of 2 or not. For more details, please refer this post.
 

How to check position of set bit ?

Simple. To check the position of its set bit we can use 0xAAAAAAAA as a mask. The mask 0xAAAAAAAA has 1 in all its odd position. So if the expression !(n & 0xAAAAAAAA) is true, position of set bit in n is even.

(0xAAAAAAAA)16 = (10101010101010101010101010101010)2

*/

// returns true if n is power of four
bool checkPowerof4(unsigned n)
{
	// return true if n is power of 2 and its only
	// set bit is present at even position
	return n && !(n & (n - 1)) && !(n & 0xAAAAAAAA);
}

int main() 
{
	unsigned n = 256;

	if (checkPowerof4(n))
		cout << n << " is power of 4";
	else 
		cout << n << " is not a power of 4";

	return 0;
}