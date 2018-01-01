/*

In this code we are are finding finding the maximu price cut by calculating all the values previously. We are taking all the possible cuts and returning the appropriate value.

*/

#include <bits/stdc++.h>
using namespace std;
 
int rodCut(int price[], int n)
{
    int T[n + 1];
 
    for (int i = 0; i <= n; i++)
        T[i] = 0;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            T[i] = max(T[i], price[j - 1] + T[i - j]);
    }
    
    return T[n];
}
 
int main()
{
    int length[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int price [] = { 1, 5, 8, 9, 10, 17, 17, 20 };
 
    int n = 4;
 
    cout << "Profit is " << rodCut(price, n);
 
    return 0;
}