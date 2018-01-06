#include <iostream>
#include <bitset>
using namespace std;

/*

We can perform better by turn off rightmost set bit of the number one by one and count the parity. The below code uses an approach like Brian Kernigan’s bit counting. The time it takes is proportional to the number of bits set.

*/

// find parity of number n
unsigned findParity(unsigned n)
{
	bool parity = false;
	
	// run till n is not zero
	while (n)
	{
		// invert the parity flag
		parity = !parity;
		
		// turn off rightmost set bit
		n = n & (n - 1);
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