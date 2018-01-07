#include <iostream>
using namespace std;

/*

Here we are using the concept that if we want to take the 17 power of 2 we will multiply 16 power of 2 and 1 power of 2. Here we check the 1 bit of power and if it is present we multiply it with the pow which we return.

*/

// Iterative solution to calculate pow(x, n) using binary operators
int power(int x, unsigned n)
{
	int pow = 1;
	
	// do till n is not zero
	while (n) 
	{
		// if n is odd, multiply result by x
		if (n & 1)
			pow *= x;
		
		// divide n by 2
		n = n >> 1;
		
		// multiply x by itself
		x = x * x;
	}

	// return result
	return pow;
}

int main()
{
	int x = -2;
	unsigned n = 10;

	cout << "pow(" << x << "," << n << ") = " << power(x, n);

	return 0;
}
