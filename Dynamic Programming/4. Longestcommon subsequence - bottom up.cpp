#include <bits/stdc++.h>
using namespace std;

/*

The longest common subsequence (LCS) problem is the problem of finding the longest subsequence that is present in given two sequences in the same order. i.e. find a longest sequence which can be obtained from the first original sequence by deleting some items, and from the second original sequence by deleting other items.



The problem differs from problem of finding common substrings. Unlike substrings, subsequences are not required to occupy consecutive positions within the original sequences.
For example, consider the two following sequences X and Y

X: ABCBDAB
Y: BDCABA


The length of LCS is 4
LCS are BDAB, BCAB and BCBA


*/

int LCSLength(string X, string Y)
{
    int m = X.length(), n = Y.length();

    int lookup[m + 1][n + 1];
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

    return lookup[m][n];
}

int main()
{
    string X = "XMJYAUZ", Y = "MZJAWXU";
    
    cout << "The length of LCS is " << LCSLength(X, Y);

    return 0;
}

/*

Let take an example. Suppose we are finding lcs but starting from start not with end. Then we add 1 to the output we get from the remaining string. Istead in bottom up approach we add 1 and save it for future. future function will use this one to add it in himself and last element will the value. So only the work direction is changing it is all samehappening.

In this code we check every posssiblity with first letter of one string to all letters of another string. and in end we return the value when both strings get exausted.

*/
















