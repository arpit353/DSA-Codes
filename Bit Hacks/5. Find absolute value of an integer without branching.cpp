#include <iostream>
#include <bitset>
using namespace std;

/*

We can use the expression ((n + mask) ^ mask) where mask is (n >> 31) (assuming 32 bit storage for integers) to compute the absolute value of n. The mask (n >> 31) will be evaluated to 0 for positive numbers and -1 for negative numbers(when we take left shift for 31 times then all the digits will become 1 because sign digit is passed to the right and 0 from the end is dropped and all 1 corresponds to -1 in 2's complement form.) For instance,

00000110                     (n = 6)
00000000                     (mask = 0)

00000110   ^                 (n + mask)
00000000                     (mask)
~~~~~~~~
00000110                     abs(n)
 
11111010                     (n = -6)
11111111                     (mask = -1)

11111001   ^                 (n + mask)
11111111                     (mask)
~~~~~~~~
00000110                     abs(n)

*/

int main() 
{
	int n = -6;
	int const mask = n >> sizeof(int) * 8 - 1;

	cout << "n (" << n << ") in binary is " << bitset<8>(n) << endl;
	cout << "mask (" << mask << ") in binary is " << bitset<8>(mask) << endl;
	cout << "n + mask (" << n + mask << ") in binary is " << bitset<8>(n + mask);

	cout << "\n\nabs(" << n << ") is " << ((n + mask) ^ mask);
	
	return 0;
}