#include <iostream>
#include <bitset>
using namespace std;

/*

The idea is to use bitwise ^ and << operators. By using expression (1 << (k - 1)), we get a number which has all bits 0, except the k’th bit. If we do bitwise XOR of this expression with n i.e. (n ^ (1 << k)), we can easily toggle its k-th bit as (0 ^ 1 = 1) and (1 ^ 1 = 0).

*/

// Function to toggle k'th bit of n
int toggleKthBit(int n, int k)
{
	return n ^ (1 << (k - 1));
}

int main()
{
	int n = 20;
	int k = 3;

	cout << n << " in binary is " << bitset<8>(n) << endl;
	cout << "Toggling k'th bit of n\n";
	n = toggleKthBit(n, k);
	
	cout << n << " in binary is " << bitset<8>(n) << endl;
	
	return 0;
}