#include <iostream>
#include <cmath>
using namespace std;

/*

The idea is to unset rightmost bit of n till only one bit is left which will be the last set bit of the given number. To handle the case when n itself is power of 2, we decrement n by 1 in the beginning. Note that this operation will not have any impact on output as we’re only concerned about last set bit of n.

1 '1' bit will be left at the end as n & n-1 is in while. So when it will become 0 n value will not change.  

*/

// compute power of two greater than or equal to n
unsigned nextPowerOf2(unsigned n)
{
	// decrement n (to handle cases when n itself 
	// is a power of 2)
	n = n - 1;
	
	// do till only one bit is left
	while (n & n - 1)
		n = n & n - 1;	// unset rightmost bit

	// n is now a power of two (less than n)
	
	// return next power of 2
	return n << 1;
}

int main()
{
	unsigned n = 127;

	cout << "Next power of 2 is " << nextPowerOf2(n);

	return 0;
}
