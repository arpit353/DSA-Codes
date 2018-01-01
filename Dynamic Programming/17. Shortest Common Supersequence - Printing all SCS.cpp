#include <bits/stdc++.h>
using namespace std;
 
#define MAX 20
 
int lookup[MAX][MAX];

/*

This code is similar to printing all lcs but the only difference is we are adding the remaining string to the result if one string become empty. ALso here we are moving in the direction with less value in look up table.  

Also if both direction are equal then we will move in both direction as suggested by the printing all lcs code. In the end we will merge both vectors to return final vector.

*/

vector<string> SCS(string X, string Y, int m, int n)
{
    if (m == 0)
    {
        vector<string> v;
        v.push_back(Y.substr(0, n));
        return v;
    }
 
    else if (n == 0)
    {
        vector<string> v;
        v.push_back(X.substr(0, m));
        return v;
    }
 
    if (X[m - 1] == Y[n - 1])
    {
        vector<string> scs = SCS(X, Y, m - 1, n - 1);
        
        for (string &str : scs)         // don't remove &
            str.push_back(X[m - 1]);
 
        return scs;
    }
 
    if (lookup[m - 1][n] < lookup[m][n - 1])
    {
        vector<string> scs = SCS(X, Y, m - 1, n);
 
        for (string &str : scs)         // don't remove &
            str.push_back(X[m - 1]);
 
        return scs;
    }
 
    if (lookup[m][n - 1] < lookup[m - 1][n])
    {
        vector<string> scs = SCS(X, Y, m, n - 1);
 
        for (string &str : scs)         // don't remove &
            str.push_back(Y[n - 1]);
 
        return scs;
    }
 
    vector<string> top = SCS(X, Y, m - 1, n);
    for (string &str : top)         // don't remove &
            str.push_back(X[m - 1]);
 
    vector<string> left = SCS(X, Y, m, n - 1);
    for (string &str : left)         // don't remove &
        str.push_back(Y[n - 1]);
 
    top.insert(top.end(), left.begin(), left.end());
 
    return top;
}
 
int SCSLength(string X, string Y, int m, int n)
{
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
 
set<string> SCS(string X, string Y)
{
    int m = X.length(), n = Y.length();
 
    SCSLength(X, Y, m, n);
 
    vector<string> v = SCS(X, Y, m, n);
 
    set<string> scs(v.begin(), v.end());
 
    make_move_iterator(v.end())); 
    
    return scs;
}
 
int main()
{
    string X = "ABCBDAB", Y = "BDCABA";
 
    set<string> scs = SCS(X, Y);
 
    cout << "All Shortest Common Supersequence of " << X << 
            " and " << Y << " are -" << "\n\n";
 
    for (string str : scs)
            cout << str << endl;
 
    return 0;
}