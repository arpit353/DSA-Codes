#include <iostream>
#include <bitset>
using namespace std;

/*
We know that the expression (n & (n-1)) will turn off the rightmost set bit of given number. (n-1) will have all the bits flipped after the rightmost set bit of n (including the rightmost set bit).
So (n & (n-1)) will result in last bit flipped of n.
For example, consider number 52 which is equal to 00110100 in binary and its total set bits are 3.

1st iteration of loop: n = 52

00110100   &          (n)
00110011              (n-1)
~~~~~~~~
00110000

 
2nd iteration of loop: n = 48

00010000   &          (n)
00101111              (n-1)
~~~~~~~~
00100000

 
3nd iteration of loop: n = 32

00100000   &          (n)
00011111              (n-1)
~~~~~~~~
00000000              (n = 0)

*/

// Function to count number of set bits in n
int numOfSetBits(int n)
{
	// stores the total bits set in n
	int count = 0;

	for (; n; count++)
		n = n & (n - 1); // clear the least significant bit set
	
	return count;
}

int main()
{
	int n = -1;

	cout << n << " in binary is " << bitset<32>(n) << endl;
	cout << "The number of set bits in " << n << " is " 
			<< numOfSetBits(n) << endl;
	
	return 0;
}
