#include <iostream>
#include <bitset>
using namespace std;

/*

Important point is it does not matter if even number of 1 are removed from the number. When we take the XOR between 2 numbers it will become 0 when both the bits will be zero. So 2 1 will become 0. And it would not effect our result as we are counting weather it has even no of 1 or not.

The idea is to calculate the parity of an integer by recursively dividing the (32-bit) integer into two equal halves and take their XOR until only 1 bit is left. Taking the XOR will cancel out set bits at same position in two halves and since parity will not be effected if we take out even set bits from it (why?), we successfully reduce the problem into half at each step.

For example, we initially split the 32-bit (4 byte) integer into two 16-bit chunks and take their XOR. Then we again split 16-bit chunk into 8-bit chunks and take their XOR. Then 8-bit chunks further get divided into 4-bits chunks and so on.. We continue this process until only 1 bit is le


*/

// Function to find parity of number x
int findParity(int x)
{
	// recursively divide the (32-bit) integer into two equal 
	// halves and take their XOR until only 1 bit is left
	
	x ^= x >> 16;
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;
	
	// return the last bit
	return x & 1;
}

int main()
{
	int x = 15;
	
	cout << x << " in binary is " << bitset<8>(x) << endl;
	
	if (findParity(x))
		cout << x << " contains odd bits";
	else 
		cout << x << " contains even bits";

	return 0;
}
