#include <iostream>
#include <bitset>
using namespace std;

/*

The idea is to use bitwise << and | operators. By using expression (1 << (k - 1)), we get a number which has all bits 0, except the k’th bit. If we do bitwise OR of this expression with n i.e. (n | (1 << (k - 1))), we get a number which has all bits same as n except the k’th bit which will be set to 1.

For example, consider n = 20 and k = 4.

00010100   |             (n = 20)
00001000                 (1 << (4 - 1))
~~~~~~~~
00011100

*/

// Function to turn on k'th bit in n
int turnOnKthBit(int n, int k)
{
	return n | (1 << (k - 1));
}

int main()
{
	int n = 20;
	int k = 4;
	
	cout << n << " in binary is " << bitset<8>(n) << endl;
	cout << "Turning k'th bit on\n";
	n = turnOnKthBit(n, k);
	cout << n << " in binary is " << bitset<8>(n) << endl;
	
	return 0;
}