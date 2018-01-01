#include <bits/stdc++.h>
using namespace std;
 
#define M 20
#define N 25
 
int lookup[M][N];

/*

In this question we have to print the string such that how we can convert a string to another. For that we find the LCS between two strings. While printing we take care that if we moved diagonally we print normally. Otherwise if we had to move leftward that means y string has it and x did not that why print it with a + symbol. Otherwise when we print moved up side that means y does not have it that why we print - symbol. 

*/

// Function to display the differences between two strings
void Diff(string X, string Y, int m, int n)
{
    if (m > 0 && n > 0 && X[m - 1] == Y[n - 1]) 
    {
        Diff(X, Y, m - 1, n - 1);
        cout << "  " << X[m - 1];
    }
 
    else if (n > 0 && (m == 0 || lookup[m][n - 1] >= lookup[m - 1][n])) 
    {
        Diff(X, Y, m, n - 1);
        cout << " +" << Y[n - 1];
    }
    
    else if (m > 0 && (n == 0 || lookup[m][n - 1] < lookup[m - 1][n])) 
    {
        Diff(X, Y, m - 1, n);
        cout << " -" << X[m - 1];
    }
}
 
void LCSLength(string X, string Y, int m, int n)
{
    for (int i = 0; i <= m; i++)
        lookup[i][0] = 0;
 
    for (int j = 0; j <= n; j++)
        lookup[0][j] = 0;
 
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
    string X = "ABCDFGHJQZ";
    string Y = "ABCDEFGIJKRXYZ";
    int m = X.length(), n = Y.length();
 
    LCSLength(X, Y, m, n);
 
    Diff(X, Y, m, n);
 
    return 0;
}