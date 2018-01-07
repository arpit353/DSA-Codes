#include <iostream>
#include <math.h>
using namespace std;

/*

A simple solution would be to calculate log4n for given number n. If it returns an integral value, then we can say that the number is power of four.

*/

// returns true if n is power of four
bool checkPowerof4(unsigned n)
{
	// find log4(n)
	double i = log(n) / log(4);

	// return true if log4(n) is an integer
	return i == trunc(i);
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