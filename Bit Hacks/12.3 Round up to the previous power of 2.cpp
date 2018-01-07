#include <iostream>
#include <cmath>
using namespace std;

/*

The idea is to calculate the position p of last set bit of n and return a number with its p’th bit set. In other words, we drop all set bits from n except its last set bit.

*/

// compute power of two less than or equal to n
unsigned previousPowerOf2(unsigned n)
{
	// drop all set bits from n except its last set bit
	return 1U << (int)log2(n);
}

int main() 
{
	unsigned n = 20;

	cout << "Previous power of 2 is " << previousPowerOf2(n);
	
	return 0;
}
