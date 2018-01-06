#include <iostream>
#include <bitset>
using namespace std;

/*

The idea is to use bitwise << and & operators. By using expression (1 << (k - 1)), we get a number which has all bits 0, except the k’th bit. If we do bitwise AND of this expression with n i.e. (n | (1 << k)), any non-zero value means that its k-th bit is set.

For example, consider n = 20 and k = 3.

00010100   &             (n = 20)
00000100                 (1 << (3-1))
~~~~~~~~
00000100                 non-zero value

*/

// Function to check if k'th bit is set for n or not
int isKthBitset(int n, int k)
{
	return n & (1 << (k - 1));
}

int main()
{
	int n = 20;
	int k = 3;

	cout << n << " in binary is " << bitset<8>(n) << endl;

	if (isKthBitset(n, k))
	    cout << "k-th bit is set";
    else
    	cout << "k-th bit is not set";

	return 0;
}
