#include <iostream>
#include <bitset>
using namespace std;

/*

As discussed above, the expression (n & (n – 1)) will unset the rightmost set bit of a number. If the number is power of 2, it has only one bit set and (n & (n – 1)) will unset the only set bit. So we can say that (n & (n – 1)) returns 0 if n is power of 2 else it is not a power of 2.

For example,


00010000   &             (n = 16, only one set bit)
00001111                 (n-1 = 15)
~~~~~~~~
00000000

*/

bool isPoweroftwo(unsigned n)
{
	cout << n << " in binary is " << bitset<8>(n) << "\n";
	cout << n - 1 << " in binary is " << bitset<8>(n-1) << "\n\n";
	
	return !(n & (n - 1));
}

int main()
{
	unsigned n = 16;
	
	if (isPoweroftwo(n))
		cout << n << " is power of two";
	else
		cout << n << " is not a power of two";
	
	return 0;
}