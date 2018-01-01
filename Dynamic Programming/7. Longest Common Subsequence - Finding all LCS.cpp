#include <bits/stdc++.h>
using namespace std;

#define M 20
#define N 25

int lookup[N][N];

/*

In this code we have to return strings. for that we store the strings in a vector. Also as we have discussed in the previous code we move in diagonal direction first. If diagonal element is present we add the letter to all the strings that was already in the set of lcs because all of them will contain this letter. 

We also changed the code here. in case both left and top side have same elemet we travel both side and add them and return the strings of both side. 

Try to vsualise the code for better understanding.

*/

vector<string> LCS(string X, string Y, int m, int n)
{
    if (m == 0 || n == 0)
    {
        vector<string> v(1);
        return v;
    }

    if (X[m - 1] == Y[n - 1])
    {
        vector<string> lcs = LCS(X, Y, m - 1, n - 1);

        for (string &str : lcs)   
            str.push_back(X[m - 1]);

        return lcs;
    }

    if (lookup[m - 1][n] > lookup[m][n - 1])
        return LCS(X, Y, m - 1, n);

    if (lookup[m][n - 1] > lookup[m - 1][n])
        return LCS(X, Y, m, n - 1);

    vector<string> top = LCS(X, Y, m - 1, n);
    vector<string> left = LCS(X, Y, m, n - 1);

    top.insert(top.end(), left.begin(), left.end());

    return top;
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

set<string> LCS(string X, string Y)
{
    int m = X.length(), n = Y.length();

    LCSLength(X, Y, m, n);

    vector<string> v = LCS(X, Y, m, n);

    set<string> lcs(make_move_iterator(v.begin()), make_move_iterator(v.end()));


    return lcs;
}

int main()
{
    string X = "ABCBDAB", Y = "BDCABA";

    set<string> lcs = LCS(X, Y);

    for (string str : lcs)
        cout << str << endl;

    return 0;
}
