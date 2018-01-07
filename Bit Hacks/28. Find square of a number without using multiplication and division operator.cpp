#include <iostream>
using namespace std;

/*

if n is even, square of n can be expressed as
n2 = (n/2)4

if n is odd, square of n can be expressed as
n2 = ((n – 1) + 1)2 = (n – 1)2 + 1 + 2 * (n – 1)*1 = (n/2)4 + 1 + (n/2)*4

<<2 is used to multiply with 4.

*/

int findSquare(int num)
{
	// base case
	if(num < 2)
		return n;

	// convert number to postive if it is negative
	num = abs(num);
	
	// drop last bit from num (divide it by 2)
	int i = num >> 1;
	
	// if num is odd
	if (num & 1)
		return ((findSquare(i) << 2) + (i << 2) + 1);
	// if num is even
	else
		return (findSquare(i) << 2);
}

int main()
{
	cout << findSquare(8);

	return 0;
}
