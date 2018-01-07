#include <iostream>
#include <bitset>
using namespace std;

/*

We can use a lookup table to find parity in constant time. An integer in C/C++ usually takes 4 bytes for storage. That means maximum number it can store is 232-1. A lookup table for all 232-1 integers will be infeasible (Not to forget, we have negative numbers too). The trick is to create an 8-bit (1 byte) version of the table, then iterate over each byte in the integer to be checked and summing the results of the table lookup.

1 byte with all its bits set is 255 in decimal (11111111 in binary) and all bits unset is 0 in decimal (00000000 in binary). So lookup table should be of size 256 (0-255)

*/

/*
Consider n = 1691315356 (binary 01100100110011110110110010011100),
 
1. Split the 32-bit integer into 16-bit chunks
0110010011001111 | 0110110010011100

2. Take their XOR
0110010011001111 ^
0110110010011100
~~~~~~~~~~~~~~~~
0000100001010011

3. Split the 16-bit result into 8-bit chunks
00001000 | 01010011

4. Take their XOR
00001000 ^
01010011
~~~~~~~~
01011011

*/

// macros to generate the lookup table (at compile-time)
#define P2(n) n, n^1, n^1, n
#define P4(n) P2(n), P2(n^1), P2(n^1), P2(n)
#define P6(n) P4(n), P4(n^1), P4(n^1), P4(n)
#define FIND_PARITY P6(0), P6(1), P6(1), P6(0)
 
// lookup-table to store the parity of each index of the table
// The macro FIND_PARITY generates the table
unsigned int lookup[256] = { FIND_PARITY };
 
// Function to find parity of x
int findParity(int x)
{
	// print lookup table (parity of integer i)
	// for (int i = 0; i < 256; i++)
	//	cout << "Parity of " << i << " is " << lookup[i] << "\n";
 
	// assuming 32-bit(4 byte) integer, break the integer into 
	// 16-bit chunks and take their XOR
	x ^= x >> 16;
	
	// Again split 16-bit chunk into 8-bit chunks and take their XOR
	x ^= x >> 8;
	
	// Note mask used 0xff is 11111111 in binary
	return lookup[x & 0xff];
}

int main()
{
	int x = 17;
	
	cout << x << " in binary is " << bitset<8>(x) << endl;
	
	if (findParity(x))
		cout << x << " contains odd bits";
	else 
		cout << x << " contains even bits";

	return 0;
}