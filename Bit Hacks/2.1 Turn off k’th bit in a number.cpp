#include <iostream>
#include <bitset>
using namespace std;

/*

We have shifted k-1 times because if we do not shift at all it is 1st bit. If we want to change 2nd bit we have to shift 1 time. That's why we shifted k-1 times.

The idea is to use bitwise <<, & and ~ operators. By using expression ~ (1 << (k - 1)), we get a number which has all its bits set, except the k’th bit. If we do a bitwise AND of this expression with n i.e. (n & ~(1 << (k - 1))), we get a number which has all bits same as n except the k’th bit which will be set to 0.


For example, consider n = 20 and k = 3.

00010100   &             (n = 20)
11111011                 ~ (1 << (3-1))
~~~~~~~~
00010000

*/
 
// Function to turn off k'th bit in n
int turnOffKthBit(int n, int k)
{
    return n & ~(1 << (k - 1));
}
 
// main function
int main()
{
    int n = 20;
    int k = 3;
    
    cout << n << " in binary is " << bitset<8>(n) << endl;
    cout << "Turning k'th bit off\n";
    n = turnOffKthBit(n, k);
    cout << n << " in binary is " << bitset<8>(n) << endl;
    
    return 0;
}