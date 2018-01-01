#include <bits/stdc++.h>
using namespace std;


/*

While finding lcs in bootom up approach when we are in any row of matrix we only need the row which is above of current row. Thats why to save space we save only the previous row and not the whole matrix.

*/

int LCSLength(string X, string Y)
{
    int m = X.length(), n = Y.length();
 
    int curr[n + 1], prev[n + 1];
 
    for (int i = 0; i <= m; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0)
                curr[j] = 0;
            else 
            {
                if (X[i - 1] == Y[j - 1])
                    curr[j] = prev[j - 1] + 1; // Natuarlly previous is one above thats why only j-1 is required.
                 else
                    curr[j] = max(prev[j], curr[j - 1]);  // prev[j] is one step above that's why we have used it here.
            }
        }
 
        for (int i = 0; i <= n; i++)
            prev[i] = curr[i];
    }
 
    return curr[n];
}
 
int main()
{
    string X = "XMJYAUZ", Y = "MZJAWXU";
 
    cout << "The length of LCS is " << LCSLength(X, Y);
 
    return 0;
}