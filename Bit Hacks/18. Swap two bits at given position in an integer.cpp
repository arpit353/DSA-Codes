#include <iostream>
#include <bitset>
using namespace std;

/*

Make a number with all 0 and only 1 at required position, Take And. It will give the bit of that position. Then move the same distance towards right so that the final vlaue become 0 or 1.

We can solve this problem by checking if the two bits at given positions are same or not. If they are same, nothing needs to be done else if they are not the same (i.e one is 0 and other is 1), then we can simply XOR them with (1 << pos) where pos is given positions. This will work because

XOR with 1 will toggle the bits
0 ^ 1 = 1
1 ^ 1 = 0

XOR with 0 will have no impact
0 ^ 0 = 0
1 ^ 0 = 1

*/

// Function to swap bits are position p and q in integer n
int swap(int n, int p, int q)
{
	// if bits are different at position p and q
	if (((n & (1 << p)) >> p) ^ ((n & (1 << q)) >> q))
	{
		n ^= (1 << p);
		n ^= (1 << q);
	}
	return n;
}

int main() 
{
	int n = 31;
	int p = 2, q = 6;
	
	cout << n << " in binary is " << bitset<8>(n) << endl;
	n = swap (n, p, q);
	cout << n << " in binary is " << bitset<8>(n) << endl;
	
	return 0;
}