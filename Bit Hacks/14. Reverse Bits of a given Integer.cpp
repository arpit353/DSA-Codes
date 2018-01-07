#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

/*

 The idea is to find position of the rightmost set bit in the number, and set the corresponding bit in result and finally unset the rightmost set bit. We repeat this till all set bits are processed.

 We can find the position of set bit by taking the log.

*/

// Integer size in C
#define INT_SIZE 32

// Function to reverse bits of a given integer
int reverseBits(int n)
{
	// store reversed bits of n. Initially all bits are set to 0
	int reverse = 0;

	// do till all set bits are processed
	while (n)
	{
		// find position of the rightmost set bit
		int pos = log2(n & -n) + 1;
		
		// set corresponding bit in result (set leftmost bit at position pos)
		reverse = reverse | (1 << (INT_SIZE - pos));
		
		// unset the rightmost set bit of a number
		n = n & (n - 1);
	}
	
	return reverse;
}

int main()
{
	int n = -100;

	cout << n << " in binary is " << bitset<32>(n) << endl;
	cout << "On reversing bits " << bitset<32>(reverseBits(n)) << endl;

	return 0;
}
