#include <iostream>
#include <bitset>
using namespace std;

/*

Just Look in the diagram for better understanding.

Given two 16-bit positive values stored in 32-bit integer variables, find the product using the 8-bit multiply operator that that takes two 8-bit numbers and returns a 16-bit value.
 
The idea is to divide the given 16-bit numbers (say m and n) into 8-bit numbers first (say mLow, mHigh & nLow, nHigh). Now the problem is reduced to something similar to multiplication of a 2-digit number with another 2-digit number. For example,
 

                                   [mHigh mLow]    X
                                   [nHigh nLow]
                                   —————————————-
                    [mHigh * nLow] [mLow * nLow]
    [mHigh * nHigh] [mLow * nHigh]
——————————————————————————————————————————————————————————————–
[mHigh * nHigh] + [mLow * nHigh + mHigh * nLow] + [mLow * nLow]
——————————————————————————————————————————————————————————————–

In the solution below, we are using unsigned char to represent a 8-bit number and unsigned short to represent 16-bit number.

*/


// multiply two 8-bit numbers m and n (unsigned char)
// and return 16-bit number (unsigned short)
unsigned short multiply8bit(unsigned char m, unsigned char n)
{
	return m*n;
}

// Multiply 16-bit integers using 8-bit multiplier
int multiply16bit(int m, int n)
{
	unsigned char mLow = (m & 0x00FF);			// stores first 8-bits of m
	unsigned char mHigh = (m & 0xFF00) >> 8;	// stores last 8-bits of m
	
	unsigned char nLow = (n & 0x00FF);			// stores first 8-bits of n
	unsigned char nHigh = (n & 0xFF00) >> 8;	// stores last 8-bits of n
	
	unsigned short mLow_nLow = multiply8bit(mLow, nLow);
	unsigned short mHigh_nLow = multiply8bit(mHigh, nLow);
	unsigned short mLow_nHigh = multiply8bit(mLow, nHigh);
	unsigned short mHigh_nHigh = multiply8bit(mHigh, nHigh);

	// return 32-bit result (don't forget to shift mHigh_nLow and mLow_nHigh
	// by 1 byte and mHigh_nHigh by 2 bytes)
	return mLow_nLow + ((mHigh_nLow + mLow_nHigh) << 8) + (mHigh_nHigh << 16);
}

int main()
{
	// 16-bit numbers stored in a 32-bit integer
	int m = 23472, n = 2600;

	cout << m << " in binary is " << bitset<16>(m) << endl;
	cout << n << " in binary is " << bitset<16>(n) << endl;

	cout << "\nNormal multiplication m * n = " << m * n;
	cout << "\nUsing 8-bit multiplier m * n = " << multiply16bit(m, n);

	return 0;
}