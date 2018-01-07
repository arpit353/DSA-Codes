#include <iostream>
#include <bitset>
using namespace std;

/*

Given an integer, swap adjacent bits of it. In other words, swap bits present at even positions with those present in odd positions.
For example,
Input:  00101101011001010111000110001001

Output: 00011110100110101011001001000110

Explanation: (Every pair of adjacent bits swapped)

00 10 11 01 01 10 01 01 01 11 00 01 10 00 10 01
00 01 11 10 10 01 10 10 10 11 00 10 01 00 01 10

*/

/*

Use Mask to seperate the odd position 1 and even position 1. Then Sift them in their respective sides and merge them.

1. SEPARATE

00101101011001010111000110001001  &    (n)
10101010101010101010101010101010       (0xAAAAAAAA)
————————————————————————————————
00101000001000000010000010001000       (Contains all even bits)
 

00101101011001010111000110001001  &    (n)
01010101010101010101010101010101       (0x55555555)
————————————————————————————————
00000101010001010101000100000001       (Contains all odd bits)
 

2. SHIFT & MERGE

00010100000100000001000001000100  |    (Right shift even bits by 1)
00001010100010101010001000000010       (Left shift odd bits by 1)
————————————————————————————————
00011110100110101011001001000110       (Adjacent bits swapped)

*/

// Function to swap adjacent bits of a given number
inline int swapAdjacentBits(int n)
{
	return (((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1));
}

int main()
{
	int n = 761622921;

	cout << n << " in binary is " << bitset<32>(n) << endl;

	n = swapAdjacentBits(n);
	cout << "After swapping " << endl;

	cout << n << " in binary is " << bitset<32>(n) << endl;

	return 0;
}
