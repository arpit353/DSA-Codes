#include <iostream>
#include <bitset>
using namespace std;


/*
Given an integer, swap consecutive b bits starting from given positions in binary representation of the integer. The bits to be swapped should not overlap with each other.

For example,

Input:
n = 15 (15 in binary is 00001111)
p = 2, q = 5 (3rd and 6th bit from the right)
b = 2 (Number of consecutive bits in each sequence)

Output: 99
(99 in binary is 01100011)

*/

/*

Just remember this logic.

Note that the result is undefined if the sequences overlap.
 
For example, consider n = 15, p = 2, q = 5 (3rd and 6th bit from the right) and number of consecutive bits in each sequence b = 2.

00001111                 (n = 15)

00000011   ^             (n >> p)
00000000                 (n >> q)
~~~~~~~~
00000011                 ((n >> p) ^ (n >> q))
 

00000011   &             ((n >> p) ^ (n >> q))
00000011                 ((1 << b) - 1)
~~~~~~~~
00000011                 x
 

00001100   |             (x << p)
01100000                 (x << q)
~~~~~~~~
01101100                 ((x << p) | (x << q))
 

00001111   ^             (n = 15)
01101100                 (n ^ ((x << p) | (x << q)))
~~~~~~~~
01100011

*/

// Function to swap b-bits starting from position p and q in an integer n
int swap(int n, int p, int q, int b)
{
	// take XOR of bits to be swapped
	int x = ((n >> p) ^ (n >> q));
	
	// consider only last b-bits of x
	x = x & ((1 << b) - 1);

	// replace the bits to be swapped with the XOR bits
	// and take its XOR with n
	return n ^ ((x << p) | (x << q));
}

int main() 
{
	int n = 15;
	int p = 2, q = 5; // (3rd and 6th bit from the right)
	int b = 2;    // number of consecutive bits in each sequence

	cout << n << " in binary is " << bitset<8>(n) << endl;
	n = swap (n, p, q, b);
	cout << n << " in binary is " << bitset<8>(n) << endl;
	
	return 0;
}
