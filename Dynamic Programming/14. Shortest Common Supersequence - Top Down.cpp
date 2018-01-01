/*

The shortest common supersequence (SCS) is the problem of finding the shortest supersequence Z of given sequences X and Y such that both X & Y are subsequences of Z.

*/

#include <bits/stdc++.h>
using namespace std;
 
int SCSLength(string X, string Y, int m, int n, auto &lookup)
{
    if (m == 0 || n == 0)
        return n + m;
 
    string key = to_string(m) + "|" + to_string(n);
 
    if (lookup.find(key) == lookup.end())
    {
        if (X[m - 1] == Y[n - 1])
            lookup[key] = SCSLength(X, Y, m - 1, n - 1, lookup) + 1;
        
        else
        
        lookup[key] = min (SCSLength(X, Y, m, n - 1, lookup) + 1, 
                              SCSLength(X, Y, m - 1, n, lookup) + 1);
    }
    
    return lookup[key];
}
 
int main()
{
    string X = "ABCBDAB", Y = "BDCABA";
    int m = X.length(), n = Y.length();
 
    unordered_map<string, int> lookup;
    
    cout << "The length of shortest Common supersequence is " 
            << SCSLength(X, Y, m, n, lookup);
 
    return 0;
}


/*
1. Let us consider two sequences X and Y of length m and n respectively that both end in the same element.

To find their SCS, we shorten each sequence by removing the last element, find the SCS of the shortened sequences, and to that SCS append the removed element. So we can say that
 

SCS(X[1..m], Y[1..n]) = SCS(X[1..m-1], Y[1..n-1]) + X[m]   if X[m] = Y[n]

For example,

SCS(‘ABCBDA’, ‘BDCABA’) = SCS(‘ABCBD’, ‘BDCAB’) + ‘A’
SCS(‘ABCBDAB’, ‘BDCAB’) = SCS(‘ABCBDA’, ‘BDCA’) + ‘B’

 
2. Now suppose that the two sequences do not end in the same element.

Then the SCS of X and Y is the shorter of the two sequences SCS(X[1..m-1], Y[1..n]) + X[m] and SCS(X[1..m], Y[1..n-1]) + Y[n]. To understand this property, let’s consider the two following sequences

X: ABCBDAB (n elements)
Y: BDCABA  (m elements)

The SCS of these two sequences either ends with a B (the last element of sequence X) or with A (the last element of sequence Y).

Case 1: If SCS ends with a B, then we add B from sequence X to SCS and the problem reduces to SCS(X[1..m-1], Y[1..n]) + X[m].
 

Case 2: If SCS does not end with a B, that means it ends with A, then we add A from sequence Y to SCS and the problem reduces to SCS(X[1..m], Y[1..n-1]) + Y[n].

For example,

SCS(‘ABCBD’, ‘BDCAB’) = minimum (SCS(‘ABCB’, ‘BDCAB’) + ‘D’,
                                 SCS(‘ABCBD’, ‘BDCA’) + ‘B’)

Below solution finds the length of shortest common supersequence of sequences X[0..m-1] and Y[0..n-1] recursively by using optimal substructure property of SCS problem.


*/