#include <iostream>

/*

0^(-1) is -1 as all the digits of 0 and 1 are different so their xor is also all 1 that's -1.

The expression ((flag^(flag-1))*n) negate n when the flag is false and the expression
((n^-flag)+flag) negate n when the flag is true.

How does it work?

1. For (flag ^ (flag – 1)) * n
if flag = 0, (0 ^ (-1)) * n = -n
if flag = 1, (1 ^ (0)) * n = n

*/

// negate only when the flag is true
int negate(int n, bool flag)
{
	return (n ^ -flag) + flag;
}

// Conditionally negate a value without branching
int main()
{
	int n = 2;
	
	std::cout << "Don't Negate " << negate(n, 0) << "\n";
	std::cout << "Negate " << negate(n, 1) << "\n";
	
	return 0;
}