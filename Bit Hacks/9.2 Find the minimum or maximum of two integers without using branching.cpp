#include <iostream>
using namespace std;

/*

To find the minimum(x, y), we can use the expression y + ((x – y) & ((x – y) >> 31))
 
 if x is greater then it x-y will be positive, sign will 0 and shifting 31 times mean all the digits will be zero. similarly when x is smaller then x-y will be negative and sign bit will be 1. when we shift 31 times it will make all digits 1.

Now if x is less than y, then (x – y) >> 31 will be -1 (all 1’s in binary representation), so

r = y + ((x – y) & ((x – y) >> 31))
r = y + ((x – y) & -1)
r = y + (x – y)
r = x

If x is more than y, then (x – y) >> 31 will be 0, so

r = y + ((x – y) & ((x – y) >> 31))
r = y + ((x – y) & 0)
r = y + (0)
r = y

Similarly, we can find the maximum(x, y) by using x – ((x – y) & ((x – y) >> 31))

*/

int findMin(int x, int y)
{
	return  y + ((x - y) & ((x - y) >> 31)); 
}

int findMax(int x, int y)
{
	return x - ((x - y) & ((x - y) >> 31));
}

int main()
{
	int x = 2, y = 4;
	
	cout << "min(" << x << ", " << y << ") is " << findMin(x, y);
	cout << "\nmax(" << x << ", " << y << ") is " << findMax(x, y);
	
	return 0;
}