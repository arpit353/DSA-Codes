#include <iostream>
using namespace std;

/*
To find the minimum(x, y), we can use the expression y ^ ((x ^ y) & -(x < y))
Now if x is less than y, then -(x < y) will be -1 (all 1’s in binary representation), so

r = y ^ ((x ^ y) & -(x < y))
r = y ^ ((x ^ y) & -1)
r = y ^ (x ^ y)
r = x

If x is more than y, then -(x < y) will be 0, so

r = y ^ ((x ^ y) & -(x < y))
r = y ^ ((x ^ y) & 0)
r = y ^ 0
r = y

To find the maximum(x, y), we can use the expression x ^ ((x ^ y) & -(x < y))
Now if x is less than y, then -(x < y) will be -1 (all 1’s in binary representation), so

r = x ^ ((x ^ y) & -(x < y))
r = x ^ ((x ^ y) & -1)
r = x ^ (x ^ y)
r = x

If x is more than y, then -(x < y) will be 0, so

r = x ^ ((x ^ y) & -(x < y))
r = x ^ ((x ^ y) & 0)
r = x ^ 0
r = x
*/

int findMin(int x, int y)
{
	return  y ^ ((x ^ y) & -(x < y)); 
}

int findMax(int x, int y)
{
	return x ^ ((x ^ y) & -(x < y));
}

int main()
{
	int x = 2, y = 4;
	
	cout << "min(" << x << ", " << y << ") is " << findMin(x, y);
	cout << "\nmax(" << x << ", " << y << ") is " << findMax(x, y);
	
	return 0;
}