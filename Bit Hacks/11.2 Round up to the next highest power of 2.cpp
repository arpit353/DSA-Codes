#include <iostream>
#include <cmath>
using namespace std;

/*

The idea is to decrement n by 1 (to handle the case when n itself is power of 2) and run a loop by initializing the result by 2. At each iteration of loop, we double result value and divide n in half and continue the loop till n becomes 0.

*/

// compute power of two greater than or equal to n
unsigned nextPowerOf2(unsigned n)
{
	// decrement n (to handle cases when n itself 
	// is a power of 2)
	n = n - 1;
	
	// initialize result by 2
	int k = 2;

	// double k and divide n in half till it becomes 0
	while (n >>= 1)
		k = k << 1; // double k

	return k;
}

/*
unsigned nextPowerOf2(unsigned n)
{
	int k = 1;
	while (k < n)
		k = k << 1;
	return k;
}
*/

int main()
{
	unsigned n = 127;

	cout << "Next power of 2 is " << nextPowerOf2(n);

	return 0;
}
