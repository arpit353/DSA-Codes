/*

The shortest common supersequence (SCS) is the problem of finding the shortest supersequence Z of given sequences X and Y such that both X & Y are subsequences of Z.

*/

#include <bits/stdc++.h>
using namespace std;
 
int SCSLength(string X, string Y)
{
    int m = X.length(), n = Y.length();
    
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
    
    return lookup[m][n];
}
 
int main()
{
    string X = "ABCBDAB", Y = "BDCABA";
    
    cout << "The length of shortest Common supersequence is " 
            << SCSLength(X, Y);
 
    return 0;
}

/*

Refer top down approach for better understanding.

We can also solve this problem in bottom-up manner. In the bottom-up approach, we calculate the smaller values of SCS(i, j) first, then build larger values from them.


            | j                                      (if i == 0)
            | i                                      (if j == 0)
SCS[i][j] = | SCS[i-1][j-1] + 1                      (if X[i-1] == Y[j-1])
            | min (SCS[i-1][j] + 1, SCS[i][j-1] + 1) (if X[i-1] != Y[j-1])
            
            

*/