#include <iostream>
using namespace std;

/*

The idea is X and Y have differences. We can find the differences on which bits they have differences by taking their XOR. Then we take the differences between Y and (the differnce Between X and Y). So if we think logically it will return the value of X to Y. Similarly we have successfully given the value of X to Y now we will extract the value of orignal Y by taking its xor with (differnce) and new Y(old X). 

*/


void swap(int &x, int &y)
{
	if (x != y)
	{
		x = x ^ y;
		y = x ^ y;
		x = x ^ y;
	}
}

int main()
{
	int x = 3, y = 4;

	cout << "Before swap: x = " << x << " and y = " << y;
	swap(x, y);
	cout << "After swap: x = " << x << " and y = " << y;

	return 0;
}