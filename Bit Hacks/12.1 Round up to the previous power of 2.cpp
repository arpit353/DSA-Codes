#include <iostream>
#include <cmath>
using namespace std;

/*

Same as previous but here we are not shifting by 1.

*/

// compute power of two less than or equal to n
unsigned previousPowerOf2(unsigned n)
{
	// do till only one bit is left
	while (n & n - 1)
		n = n & n - 1;	// unset rightmost bit

	// n is now a power of two (less than or equal to n)
	return n;
}

int main()
{
	unsigned n = 128;

	cout << "Previous power of 2 is " << previousPowerOf2(n);

	return 0;
}
