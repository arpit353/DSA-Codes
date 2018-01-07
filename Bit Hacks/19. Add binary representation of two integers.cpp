#include <bits/stdc++.h>
using namespace std;

/*

Given two integers, add their binary representation.
For example,

Input: 
x = 12731 (which is 0011000110111011 in binary)
y = 38023 (which is 1001010010000111 in binary)

Output: 1100011001000010

Input:

x = 1023 (which is 0000001111111111 in binary)
y = 1023 (which is 0000001111111111 in binary)

Output: 0000011111111110

*/

/*

So the idea is to extract each bit from both integers one by one from LSB to MSB and store their addition result in an array of size of integer. If addition results in a carry, we propagate the carry to next pair of bits. Below implementation uses LEFT shift and AND binary operator


*/

// macro that defines the size of an integer
// assuming 2 byte storage for integer
#define SIZE 16

// Function to add x and y in binary
int* add(int x, int y)
{
	int carry = 0;
	int n = SIZE;

	// create a array to store binary sum
	int* arr = (int*)malloc(n);

	for (int i = 0; i < n; i++)
	{
		// if x is 1
		if (x & (1 << i)) 
		{
			if (y & (1 << i)) // if both x and y are 1
			{
				if (carry)
					arr[n - i - 1] = 1; // carry = 1
				else
					arr[n - i - 1] = 0, carry = 1;
			}
			else // x is 1, y is 0
			{
				if (carry)
					arr[n - i - 1] = 0; // carry = 1
				else
					arr[n - i - 1] = 1; // carry = 0
			}
		}
		// if x is 0
		else 
		{
			if (y & (1 << i)) // x is 0, y is 1
			{
				if (carry)
					arr[n - i - 1] = 0; // carry = 1
				else
					arr[n - i - 1] = 1; // carry = 0
			}
			else // both x and y are 0
			{
				if (carry == 1)
					arr[n - i - 1] = 1, carry = 0;
				else
					arr[n - i - 1] = 0; // carry = 0
			}
		}
	}

	return arr;
}

int main()
{
	int x = 12731, y = 38023;

	cout << "x (" << x << ") in binary is " << bitset<16>(x) << endl;
	cout << "y (" << y << ") in binary is " << bitset<16>(y) << endl;
	
	int* arr = add(x, y);

	cout << "\nx + y is ";
	for (unsigned i = 0; i < SIZE; i++)
		printf("%d", arr[i]);

	return 0;
}

/*

Binary addition is much like decimal addition, except that it carries on a value of 2 instead of a value of 10. For example in decimal addition, if we add 9 + 6 we get 16 which in the sum gives a digit 6 and a carry of 1. Binary addition follows the similar logic.

when we add 1 and 1 (with carry of 0); the result is 2 in decimal, but since 2 is written as 10 in binary, we get, after summing 1 + 1 in binary, a digit 0 and a carry of 1.
 
Similarly, if we add 1 and 1 (with carry of 1), the result in 3 in decimal which is 11 in binary. So after summing 1 + 1 + 1 in binary, we get a digit 1 and a carry of 1.
Therefore in binary,

0 + 0 = 0
0 + 1 = 1
1 + 0 = 1
1 + 1 = 10 (which is 0 with carry 1)

with carry 1
0 + 0 (+ 1) = 1
0 + 1 (+ 1) = 10 (which is 0 with carry 1)
1 + 0 (+ 1) = 10 (which is 0 with carry 1)
1 + 1 (+ 1) = 11 (which is 1 with carry 1)

*/