#include <iostream>
#include <bitset>
using namespace std;

/*

We will off the rightmost 1 then take XOR to find the difference in the bits of number. Then we will check find its position by shifting left the 1 to right until it become 0. The no of times it took to become 0 will be the position of rightmost 1.

The idea is to unset the rightmost bit of number n and XOR the result with n. Then the position of the rightmost set bit in n will be the position of the only set bit in the result. Note that if n is odd, we can directly return 1 as first bit is always set for odd numbers.
For example, number 20 in binary is 00010100 and position of the rightmost set bit is 3.


00010100   &                   (n = 20)
00010011                       (n-1 = 19)
~~~~~~~~
00010000   ^                   (XOR result number with n)
00010100
~~~~~~~~
00000100       — rightmost set bit will tell us the position

*/

// returns position of the rightmost set bit of n
int rightmostSetBitPos(int n)
{
	// if number is odd, return 1
	if(n & 1)
		return 1;

	// unset rightmost bit and xor with number itself
	n = n ^ (n & (n - 1));
	
	// cout << bitset<8>(n) << endl;
	
	// find the position of the only set bit in the result
	// we can directly return log2(n) + 1 from the function
	int pos = 0;
	while(n)
	{
		n = n >> 1;
		pos++;
	}
	return pos;
}

int main()
{
	int n = 20;
	
	cout << n << " in binary is " << bitset<8>(n) << endl;
	cout << "Position of the rightmost set bit is " << rightmostSetBitPos(n);

	return 0;
}