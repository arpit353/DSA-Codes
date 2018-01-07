#include <iostream>
using namespace std;

/*

We have to make all the bits after leftmost 1 bit 1. So we shift by 1 and take OR to make 2 '1'. Then we make 2 shift to make 4 '1'. In this way we make all the digits 1 by doubling the number of 1 every time.

Let’s take an example of 131, which is 10000011 in binary –

n–; // 10000011 –> 10000010
n |= n >> 1; // 10000010 | 01000001 = 11000011
n |= n >> 2; // 11000011 | 00110000 = 11110011
n |= n >> 4; // 11110011 | 00001111 = 11111111
n |= n >> 8; // … (At this point all bits are 1, so further bitwise-OR
n |= n >> 16; // operations produce no effect)
n++; // 11111111 –> 100000000

There’s one bit in the 9th position, which represents 2^8, which is indeed the next largest power of 2. Each of the shifts overlaps all of the existing 1 bits in the number with some of the previously untouched 0’s, eventually producing a number of 1 bits equal to the number of bits in the original number. Adding one to that value produces a new power of 2.

*/

// compute the next highest power of 2 of 32-bit n
unsigned nextPowerOf2(unsigned n)
{
	// decrement n (to handle cases when n itself is a power of 2)
	n--;
	
	// Set all bits after the last set bit
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	
	// increment n and return
	return ++n;
}

int main() 
{
	unsigned n = 131;

	cout << "Next power of 2 is " << nextPowerOf2(n);
	
	return 0;
}