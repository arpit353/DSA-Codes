#include <iostream>
#include <bitset>
using namespace std;

/*

Given a number, check if adjacent bits are set in binary representation of it.

*/

/*
The expression (n & (n << 1) or (n & (n >> 1) will return true if n contains any pair whose adjacent bits are 1. For example,

00101101   &                 (n)
01011010                     left shift n by 1
~~~~~~~~
00001000                     (n & (n << 1))
*/

// return true if adjacent bits are set in binary representation of n
bool check(int n)
{
	return n & (n << 1);
}

int main()
{
	int n = 67;
 	
 	cout << n << " in binary is " << bitset<8>(n) << endl;
 
	if (check(n))
		cout << "Adjacent pair of set bits found";
	else
		cout << "No adjacent pair of set bits found";

	return 0;
}