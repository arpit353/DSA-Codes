#include <bits/stdc++.h>
using namespace std;
 
#define MAX 20
 
int lookup[MAX][MAX];

/*

In this problem we have to find SCS with the help pf LCS Look up table. SO first we fill the LCS Look Up Table. Then we recusively call SCS function to find the SCS string. This code is similar SCS code the only difference is that we are moving with the greater value because that's what we did during fillig the table. Since while filling the table we filled it with maimum value so that why while traversal we move to the higher value place.  

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
 
        if (lookup[m - 1][n] > lookup[m][n - 1]) // Game Point
            return SCS(X, Y, m - 1, n) + X[m - 1];
 
        else
            return SCS(X, Y, m, n - 1) + Y[n - 1];
    }
}
 
void LCS(string X, string Y, int m, int n)
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
 
            else
                lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
        }
    }
}
 
int main()
{
    string X = "ABCBDAB", Y = "BDCABA";
    int m = X.length(), n = Y.length();
 
    LCS(X, Y, m, n);
 
    cout << "The Shortest Common Supersequence of " << X << 
            " and " << Y << " is " << SCS(X, Y, m, n);
 
    return 0;
}