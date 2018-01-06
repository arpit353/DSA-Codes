#include <iostream>
#include <bitset>
using namespace std;

/*

“Parity” refers to the number of 1s in a given binary number. Odd parity(1) means there are an odd number of 1s and even parity(0) means that there are an even number of 1s. Parity bits are often used as a crude means of error detection as digital data is transmitted and received.
Naive solution would be to calculate parity by checking each bit of n one by one. The time taken is proportional to the number of bits in the number.

*/

// find parity of number n
unsigned findParity(unsigned n)
{
	bool parity = false;
	
	// run till n is not zero
	while (n)
	{
		// invert the parity flag
		if(n & 1)
			parity = !parity;
		
		// right shift n by 1 (divide by 2)
		n = n >> 1;
	}
	
	return parity;
}

int main()
{
	unsigned n = 31;
	
	cout << n << " in binary is " << bitset<8>(n) << endl;

	if (findParity(n))
		cout << "Parity of " << n << " is odd";
	else 
		cout << "Parity of " << n << " is even";

	return 0;
}