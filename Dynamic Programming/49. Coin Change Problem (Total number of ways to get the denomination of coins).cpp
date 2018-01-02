/*
Given an unlimited supply of coins of given denominations, find the total number of distinct ways to get a desired change.
For example,
 
Input: S = { 1, 3, 5, 7 }, N = 8
Total number of ways is 6

{ 1, 7 }
{ 3, 5 }
{ 1, 1, 3, 3 }
{ 1, 1, 1, 5 }
{ 1, 1, 1, 1, 1, 3 }
{ 1, 1, 1, 1, 1, 1, 1, 1 }

Input: S = { 1, 2, 3 }, N = 4
Total number of ways is 4

{ 1, 3 }
{ 2, 2 }
{ 1, 1, 2 }
{ 1, 1, 1, 1 }

*/

#include <bits/stdc++.h>
using namespace std;
 
unordered_map<string, int> lookup;
 
int count(int S[], int n, int N)
{
    if (N == 0)
        return 1;
 
    if (N < 0 || n < 0)
        return 0;
 
    string key = to_string(n) + "|" + to_string(N);
    
    if (lookup.find(key) == lookup.end())
    {
        int include = count(S, n, N - S[n]); // we have passed n because same number can occur more than one time also
    
        int exclude = count(S, n - 1, N);
    
        lookup[key] = include + exclude;
    }
    
    return lookup[key];
}
 
int main()
{
    int S[] = { 1, 2, 3 };
    int n = sizeof(S) / sizeof(S[0]);
 
    int N = 4;
 
    cout << "Total number of ways to get desired change is "
         << count(S, n - 1, N);
 
    return 0;
}