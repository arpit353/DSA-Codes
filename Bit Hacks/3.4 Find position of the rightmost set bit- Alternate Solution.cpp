#include <iostream>
#include <math.h>
using namespace std;

/*

We will use the concept that all the bits of negative of a number is same until the 1st 1. Then all are different. So when we will neagte the number and take & then all the bits till 1st one will become 0 and all the rightmost are already 0. So only 1 left is the rightmost 1. Then we will return its postion by taking its log base 2. 

00…0010100  &                  (n = 20)
11…1101100                     (-n = -20)
~~~~~~~~~~
00…0000100   

*/

// returns position of the rightmost set bit of n
int rightmostSetBitPos(int n)
{
	// if number is odd, return 1
	if(n & 1)
		return 1;

	return log2(n & -n) + 1;
}

int main()
{
	int n = 20;
	
	cout << "Position of the rightmost set bit is " << rightmostSetBitPos(n);

	return 0;
}