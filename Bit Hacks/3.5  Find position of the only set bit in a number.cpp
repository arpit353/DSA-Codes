#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;

/*

The idea is to unset the rightmost bit of number n and check if it becomes 0 or not. If it is non-zero, we know that there is another set bit present and we have invalid input. If it becomes 0, then the position of the only set bit can be found by processing every bit of n one by one or we can directly use log2(n) + 1.
For example, number 16 in binary is 00010000 and position of the rightmost set bit is 5.


00010000   &                   (n = 16)
00001111                       (n-1 = 15)
~~~~~~~~
00000000

log2(16) + 1 = 5

*/
 
// returns position of the only set bit of n
int setBitPos(int n)
{
	// unset rightmost bit and check if the number is non-zero
	if (n & (n - 1))
	{
		cout << "Wrong input";
		return 1;
	}

	return log2(n) + 1;
}
 
int main()
{
	int n = 16;
 
	cout << n << " in binary is " << bitset<8>(n) << endl; 
	cout << "Position of the only set bit is " << setBitPos(n);
 
	return 0;
}