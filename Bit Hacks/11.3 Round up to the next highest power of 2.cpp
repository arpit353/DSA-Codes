#include <iostream>
#include <cmath>
using namespace std;

/*

The idea is to calculate the position p of last set bit of n and return a number with its (p + 1) bit set.

*/

// compute power of two greater than or equal to n
unsigned nextPowerOf2(unsigned n)
{
	// decrement n (to handle the case when n itself 
	// is a power of 2) 
	n = n - 1;
	
	// calculate position of last set bit of n
	int lg = log2(n);

	// next power of two will have bit set at position (lg + 1) 
	return 1U << lg + 1;
}

int main() 
{
	unsigned n = 20;

	cout << "Next power of 2 is " << nextPowerOf2(n);
	
	return 0;
}
