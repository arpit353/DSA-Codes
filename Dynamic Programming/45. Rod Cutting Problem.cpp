/*
Given a rod of length n and list of prices of rod of length i where 1 <= i <= n, find the optimal way to cut rod into smaller rods in order to maximize profit.

For example, consider below rod lengths and values

Input:   
length[] = [1, 2, 3, 4, 5, 6, 7, 8]
price [] = [1, 5, 8, 9, 10, 17, 17, 20]
 
Best: Cut the rod into two pieces of length 2 each
to gain revenue of 5 + 5 = 10

Cut               Profit
4                  9
1, 3              (1 + 8) = 9
2, 2              (5 + 5) = 10
3, 1              (8 + 1) = 9
1, 1, 2           (1 + 1 + 5) = 7
1, 2, 1	          (1 + 5 + 1) = 7
2, 1, 1	          (5 + 1 + 1) = 7
1, 1, 1, 1        (1 + 1 + 1 + 1) = 4

*/

/*

In this problem we are dividing the are checking every subarray. We take every possible cut by taking the price element and finding the cut price of it by calling the fuction recursively.

*/

#include <bits/stdc++.h>
using namespace std;
 
int rodCut(int price[], int n)
{
    if (n == 0)
        return 0;
 
    int maxValue = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int cost = price[i - 1] + rodCut(price, n - i);
        
        if (cost > maxValue)
            maxValue = cost;
    }
 
    return maxValue;
}
 
int main()
{
    int length[] = { 1, 2, 3, 4, 5, 6, 7, 8 };    // dummy
    int price [] = { 1, 5, 8, 9, 10, 17, 17, 20 };
 
    int n = 4;
 
    cout << "Profit is " << rodCut(price, n);
 
    return 0;
}