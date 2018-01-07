#include <iostream>
#include <bitset>
using namespace std;

/*

The idea is to set all bits on the right-hand side of the most significant set bit to 1 and and then drop all bits but the last set bit from n so that it becomes equal to the previous power of two. For instance, consider number 20 (binary 00010100), we convert 00010100 to 00011111. Then we drop all set bits except the last one so that it becomes 00010000 which is equal to 16, the previous power of 20.

*/

// compute power of two less than or equal to n
unsigned nextPowerOf2(unsigned n)
{
    cout << bitset<16>(n) << endl;
    
	// Set all bits after the last set bit
	n = n | (n >> 1);
    cout << bitset<16>(n) << endl;
    
    n = n | (n >> 2);
    cout << bitset<16>(n) << endl;
        
    n = n | (n >> 4);
    cout << bitset<16>(n) << endl;
    
    n = n | (n >> 8);
    cout << bitset<16>(n) << endl;
    
    n = n | (n >> 16);
    cout << bitset<8>(n >> 1) << endl;
        
    return n - (n >> 1);
}

int main()
{
	unsigned n = 130;

	cout << "Next power of 2 is " << nextPowerOf2(n);
	
	return 0;
}
