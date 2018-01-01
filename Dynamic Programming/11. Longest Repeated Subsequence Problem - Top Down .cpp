#include <bits/stdc++.h>
using namespace std;

/*

In this question we have to find the longest subsequence which is repeated in a string. That's why we took the lcs between the same string. Also we took care that same sequence of letters is not marked repeated thats why we checked if the position of letter is not same by checking m==n

*/


int LRSLength(string X, int m, int n, auto &lookup)
{
    if (m == 0 || n == 0)
        return 0;
 
    string key = to_string(m) + "|" + to_string(n);
 
    if (lookup.find(key) == lookup.end())
    {
        if (X[m - 1] == X[n - 1] && m != n) // Game Point 2
            lookup[key] = LRSLength(X, m - 1, n - 1, lookup) + 1;
        
        else
    
        lookup[key] = max (LRSLength(X, m, n - 1, lookup), 
                          LRSLength(X, m - 1, n, lookup));
    }
    
    return lookup[key];
}
 
int main()
{
    string X = "ATACTCGGA";
    int m = X.length();
 
    unordered_map<string, int> lookup;
    
    cout << "Length of Longest Repeating Subsequence is " << 
            LRSLength(X, m, m, lookup); // Game Point 1
 
    return 0;
}