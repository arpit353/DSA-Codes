#include <bits/stdc++.h>
using namespace std;

/*

The given number n is power of 8 if it is power of 2 and its only set bit is present at
(0, 3, 6, . . .30) position.

How to check for power of 2?

The expression (n & (n - 1)) will unset the rightmost set bit of a number. If the number is power of 2, it has only one bit set and (n & (n - 1)) will unset the only set bit. So we can say that (n & (n - 1)) returns 0 if n is power of 2 else it is not a power of 2.

We can also the expression (n & -n) == n to check if a positive integer is a power of 2 or not. For more details refer this post.

How to check position of set bit ?

To check the position of its set bit we can use 0xB6DB6DB6 as a mask. The mask 0xB6DB6DB6 has 0 in all (0, 3, 6, . . .30) position. So if the expression !(n & 0xB6DB6DB6) is true, position of set bit in n is even.

(0xB6DB6DB6)16 = (10110110110110110110110110110110)2

*/

// returns true if n is power of 8
bool checkPowerof8(unsigned n)
{
	/*	for(int i = 1; i < INT_MAX; i = i*8)
		cout << bitset<32>(i) << endl;
	*/		
	// return true if n is power of 2 and its only
	// set bit is present at (0, 3, 6, ... ) position
	return n && !(n & (n - 1)) && !(n & 0xB6DB6DB6);
}

int main() 
{
	unsigned n = 512;

	if (checkPowerof8(n))
		cout << n << " is power of 8";
	else 
		cout << n << " is not a power of 8";

	return 0;
}