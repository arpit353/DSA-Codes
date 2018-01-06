#include <iostream>
#include <bitset>
using namespace std;

/*

If u look at the trend all the numbers will have n-1 bits as same as their self until the rightmost bit. When we do n-1 if will have all the same bits until the rightmost bit of n.Just think logically it will become clear. Rightmost 1 can be at the last position or all the right most digits will be zero. If all the lats digits are 0 when we subtract 1 they will become 1 and kinda logically it works.

The expression (n & (n – 1)) will turn off the rightmost set bit of given number. (n – 1) will have all the bits flipped after the rightmost set bit of n (including the rightmost set bit).
So (n & (n – 1)) will result in last bit flipped of n. Consider


00010100   &                 (n = 20)
00010011                     (n-1 = 19)
~~~~~~~~
00010000

00…00000000   &              (n = 0, no rightmost bit)
11…11111111                  (n-1 = -1)
~~~~~~~~~~~
00…00000000

*/

unsigned unsetRightmostBit(unsigned n)
{
	return n & (n - 1);
}

int main()
{
	int n = 20;
	
	cout << n << " in binary is " << bitset<8>(n) << endl;
	
	cout << "Rightmost bit of " << n << " is unset\n";
	n = unsetRightmostBit(n);

	cout << n << " in binary is " << bitset<8>(n) << endl;
	
	return 0;
}