/*
Given an unlimited supply of coins of given denominations, find the minimum number of coins required to get a desired change.
 
For example, consider S = { 1, 3, 5, 7 }
 
If desired change is 15, the minimum number of coins required is 3
(7 + 7 + 1) or (5 + 5 + 5) or (3 + 5 + 7)

If desired change is 18, the minimum number of coins required is 4

(7 + 7 + 3 + 1) or (5 + 5 + 5 + 3) or (7 + 5 + 5 + 1)

*/

/*

In this question also we are checking all the the possibilities by recusrions and returning the minimum no of coins needed. We will check all array so that because we have unlimited number of coins.

*/

#include <bits/stdc++.h>
using namespace std;
 
int findMinCoins(int S[], int n, int N)
{
    if (N == 0)
        return 0;
    
    if (N < 0)
        return INT_MAX;
    
    int coins = INT_MAX;
    
    for (int i = 0; i < n; i++) 
    {
        int res = findMinCoins(S, n, N - S[i]);
    
        if (res != INT_MAX)
            coins = min(coins, res + 1);
    }
    
    return coins;
}
 
int main()
{
    int S[] = { 1, 2, 3, 4 };
    int n = sizeof(S) / sizeof(S[0]);
    
    int N = 15;
 
    cout << "Minimum number of coins required to get desired change is "
            << findMinCoins(S, n, N);
 
    return 0;
}