/*

For example, for N = 5 the binary strings satisfies the given constraints are

00000 00001 00010 00100 00101 01000 01001 01010 10000 10001 10010 10100 10101

*/

/*

This code is also strightforward. At any point we can add 0 or 1. So we take both possibility and find the appropriate length.

While filling up the table if we are filling 0 then we can take the total of both 0 and 1. Other wise if we are filling 1 then we can take the total of only 0 as 1 is not allowed. 

*/

#include <iostream>
using namespace std;
 
int countStrings(int n)
{
    int T[n+1][2];
 
    T[0][0] = 0, T[0][1] = 0;      
    T[1][0] = 2, T[1][1] = 1;   // Here i represent the lenegth of the string at a current point
 
    for (int i = 2; i <= n; i++)
    {
        T[i][0] = T[i-1][0] + T[i-1][1];
        
        T[i][1] = T[i-1][0];
    }
    
    return T[n][0];
 
}
 
int main()
{
    int n = 5;
    
    cout << "Number of " << n << "-digit binary strings without any "
        "consecutive 1's are " << countStrings(n);
 
    return 0;
}