#include <bits/stdc++.h>
using namespace std;

#define M 20
#define N 25

int lookup[M][N];

/*

For lokup table see the look up table picture in the folder.

In this we are just moving backward in the lookup table to find the lcs.

In this question we are calculating the lcslength only to full the lookup table. While printing the lcs we start from the end. First check diagonal, if it is 1 less then it means lcs contains this letter. Otherwise move in the direction of greater element wheather it is top or bottom.    

If equal we move in top direction This will give only one solution . 

To get all the lcs we have to move in both diection and store all the lcs in it as both have contibuted equal in the subsequence.

Base condition is empty string that shows we add letters in the empty string.

*/


string LCS(string X, string Y, int m, int n)
{
    if (m == 0 || n == 0)
        return string("");

    if (X[m - 1] == Y[n - 1])
    {
        return LCS(X, Y, m - 1, n - 1) + X[m - 1];
    }

    if (lookup[m - 1][n] > lookup[m][n - 1])
        return LCS(X, Y, m - 1, n);

    else
    
        return LCS(X, Y, m, n - 1);
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
    string X = "XMJYAUZ", Y = "MZJAWXU";
    int m = X.length(), n = Y.length();

    LCSLength(X, Y, m, n);

    cout << LCS(X, Y, m, n);

    return 0;
}
