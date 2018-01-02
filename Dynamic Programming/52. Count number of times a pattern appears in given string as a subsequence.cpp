#include <iostream>
using namespace std;

/*

The idea is to use recursion to solve this problem. If we compare the last character of the string X[0..m] with last character of the pattern Y[0..n], there are two possibilities –
 
If the last character of the string is same as the last character of the pattern, we recuse for the remaining substring X[0..m-1] and Y[0..n-1]. Since we want all possible combinations, we also consider the case when current character of string do not form part of the solution. i.e. we ignore the last character of the string and recurse for the remaining substring X[0..m-1].
 
If last character of the string is different from the last character of the pattern, then we ignore the last character of the string and recurse for the remaining substring X[0..m-1]

*/

int count(string X, string Y, int m, int n)
{
    int T[m + 1][n + 1];
 
    // if pattern Y is empty, we have found subsequence
    for (int i = 0; i <= m; i++)
        T[i][0] = 1;
 
    // if input string X is empty
    for (int j = 1; j <= n; j++)
        T[0][j] = 0;
 
    // if current character of both string and pattern matches,
    // 1. exclude current character in both string and pattern
    // 2. exclude only current character in the string
 
    // else if current character of string and pattern do not match, 
    // exclude current character in the string
    
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            T[i][j] = ((X[i-1] == Y[j-1]) ? T[i-1][j-1] : 0) +
                        T[i-1][j];
 
    // return last entry in lookup table
    return T[m][n];
}
 
// main function
int main()
{
    string X = "subsequence";    // input string
    string Y = "sue";            // pattern
 
    cout << count(X, Y, X.size(), Y.size()) << endl;
 
    return 0;
}