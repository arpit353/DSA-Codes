#include <iostream>
using namespace std;

/*

The given number n is power of 4 if it is power of 2 and its remainder is 1 when it is divided by 3.

*/

// returns true if n is power of four
bool checkPowerof4(unsigned n)
{
	// return true if n is power of 2 and 
	// remainder is 1 when it is divided by 3
	return !(n & (n - 1))&& (n % 3 == 1);
}

int main() 
{
	unsigned n = 256;

	if (checkPowerof4(n))
		cout << n << " is power of 4";
	else 
		cout << n << " is not a power of 4";

	return 0;
}