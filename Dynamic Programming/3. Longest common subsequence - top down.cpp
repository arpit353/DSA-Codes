#include <bits/stdc++.h>
using namespace std;

/*

Question :-

The longest common subsequence (LCS) problem is the problem of finding the longest subsequence that is present in given two sequences in the same order. i.e. find a longest sequence which can be obtained from the first original sequence by deleting some items, and from the second original sequence by deleting other items.

The problem differs from problem of finding common substrings. Unlike substrings, subsequences are not required to occupy consecutive positions within the original sequences.
For example, consider the two following sequences X and Y

X: ABCBDAB
Y: BDCABA


The length of LCS is 4
LCS are BDAB, BCAB and BCBA

*/

int LCSLength(string X, string Y, int m, int n, auto &lookup)
{
    if (m == 0 || n == 0)
        return 0;

    string key = to_string(m) + "|" + to_string(n);

    if (lookup.find(key) == lookup.end())
    {
        if (X[m - 1] == Y[n - 1])
            lookup[key] = LCSLength(X, Y, m - 1, n - 1, lookup) + 1;

        else
        lookup[key] = max(LCSLength(X, Y, m, n - 1, lookup),
                          LCSLength(X, Y, m - 1, n, lookup));
    }

    return lookup[key];
}

int main()
{
    string X = "ABCBDAB", Y = "BDCABA";

    unordered_map<string, int> lookup;

    cout << "The length of LCS is "
        << LCSLength(X, Y, X.length(), Y.length(), lookup);

    return 0;
}

/*


Comments :-

* we start from the back otherwise we have to keep a marker of the position from where we want to use the string.
* There are two conditions

* we could have checked from the first element but then we will have to pass the current position also so that we can check from that place in the string.

* if both the string have last element same then add 1

* otherwise we don't know reducing which string will help thats why we will check both and which ever gives bigger subsequence length is returned.

*/

