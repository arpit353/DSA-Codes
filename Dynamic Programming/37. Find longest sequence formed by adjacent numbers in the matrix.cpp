/* 

Given a N x N matrix where each cell has distinct value in the 1 to N * N. Find the longest sequence formed by adjacent numbers in the matrix such that for each number, the number on the adjacent neighbor is +1 its value.

The idea is to use recursion. The problem has an optimal substructure. That means the problem can be broken down into smaller, simple “subproblems”, which can further be divided into yet simpler, smaller subproblems until the solution becomes trivial. The problem can be recursively defined as –

longest path starting from cell (i, j) =

M[i][j] + | longest path starting from cell (i-1, j) (if M[i][j]+1 = M[i-1][j])
          | longest path starting from cell (i, j-1) (if M[i][j]+1 = M[i][j-1])
          | longest path starting from cell (i, j+1) (if M[i][j]+1 = M[i][j+1])
          | longest path starting from cell (i+1, j) (if M[i][j]+1 = M[i+1][j])

*/

/*

It's Quite straightforward code just look at the code and try to understand it. 

*/

#include <bits/stdc++.h>
using namespace std;
 
#define N 6
 
unordered_map<string, string> lookup;
    
bool isValid(int i, int j)
{
    return (i >= 0 && i < N && j >= 0 && j < N);
}
 
string findLongestPath(int mat[N][N], int i, int j)
{
    if (!isValid (i, j))
        return 0;
    
    string key = to_string(i) + "|" + to_string(j);
    
    if (lookup.find(key) == lookup.end())
    {
        string path;
    
        if (i > 0 && mat[i - 1][j] - mat[i][j] == 1)
            path = findLongestPath(mat, i - 1, j);
 
        if (j + 1 < N && mat[i][j + 1] - mat[i][j] == 1)
            path = findLongestPath(mat, i, j + 1);
 
        if (i + 1 < N && mat[i + 1][j] - mat[i][j] == 1)
            path = findLongestPath(mat, i + 1, j);
 
        if (j > 0 && mat[i][j - 1] - mat[i][j] == 1)
            path = findLongestPath(mat, i, j - 1);

        // We are not considering maximu here because there can be only one of this correct so in every case only one of the fuction we go on recusrion and return the path. 
        
        lookup[key] = to_string(mat[i][j]) + " - " +  path;
    }
    
    return lookup[key];
}
 
int main()
{
    int mat[N][N] = 
    { 
        { 10, 13, 14, 21, 23 },
        { 11,  9, 22,  2,  3 },
        { 12,  8,  1,  5,  4 },
        { 15, 24,  7,  6, 20 },
        { 16, 17, 18, 19, 25 }
    };
 
    string res;                
    string str;                
    int resSize = INT_MIN;   
 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) 
        {
            string str = findLongestPath(mat, i, j);
            
            // We get the string but we have to print the size of the string that's why we will find the size of string and if it is greater than the length of string it will store it.
            
            int size = count(str.begin(), str.end(), '-');
            
            if (size > resSize)
                res = str, resSize = size;
        }
    }
    cout << res.substr(0, res.length() - 3);
 
    return 0;
} 
