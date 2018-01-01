#include <bits/stdc++.h>
using namespace std;

/*

In this question we have to find the longest subsequence which is repeated in a string. That's why we took the lcs between the same string. Also we took care that same sequence of letters is not marked repeated thats why we checked if the position of letter is not same by checking i==j

*/

int LRSLength(string X, int n)
{
    
    int lookup[n + 1][n + 1];
 
    for (int i = 0; i <= n; i++)
        lookup[i][0] = 0;
 
    for (int j = 0; j <= n; j++)
        lookup[0][j] = 0;
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == X[j - 1] && i != j) // Game Point 2
                lookup[i][j] = lookup[i - 1][j - 1] + 1; 
 
            else
                lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
        }
    }
    
    return lookup[n][n];
}
 
int main()
{
    string X = "ATACTCGGA";
 
    int n = X.length();
 
    cout << "Length of Longest Repeating Subsequence is " << 
            LRSLength(X, n); //Game Point 1
 
    return 0;
}
