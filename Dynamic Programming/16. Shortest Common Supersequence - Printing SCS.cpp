#include <bits/stdc++.h>
using namespace std;
 
#define MAX 20
 
int lookup[MAX][MAX];

/*

This code is similar to Printing LCS. We are finding the length only to fill the lookup table. The only difference is whenever the diagonal element does not match we check top and left side of the current element. In LCS we moved towards the place with higher value but in this we will move towards lower value since we are calculating shortest common sequence.

*/

string SCS(string X, string Y, int m, int n)
{
    if (m == 0)
        return Y.substr(0, n);
 
    else if (n == 0)
        return X.substr(0, m);
 
    if (X[m - 1] == Y[n - 1])
        return SCS(X, Y, m - 1, n - 1) + X[m - 1];
    
    else
    { 
        if (lookup[m - 1][n] < lookup[m][n - 1]) // Game Point 
            return SCS(X, Y, m - 1, n) + X[m-1];
 
        else
            return SCS(X, Y, m, n - 1) + Y[n-1];
    }
}
 
int SCSLength(string X, string Y, int m, int n)
{
    
    int lookup[m + 1][n + 1];
 
    for (int i = 0; i <= m; i++)
        lookup[i][0] = i;
 
    for (int j = 0; j <= n; j++)
        lookup[0][j] = j;
 
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
        
            else
                lookup[i][j] = min(lookup[i - 1][j] + 1, 
                lookup[i][j - 1] + 1);
        }
    }
}
 
int main()
{
    string X = "ABCBDAB", Y = "BDCABA";
    int m = X.length(), n = Y.length();
 
    SCSLength(X, Y, m, n);
 
    cout << "The Shortest Common Supersequence of " << X << 
            " and " << Y << " is " << SCS(X, Y, m, n);
 
    return 0;
}