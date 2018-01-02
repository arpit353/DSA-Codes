/*

Given a M x N matrix where each cell can have value of 1, 0 or -1, where -1 denotes a unsafe cell, collect maximum number of ones starting from first cell and by visiting only safe cells (i.e. 0 or 1). We are allowed to go only left or down if the row is odd else, we can only go only right or down from current cell.

*/

/*

Important point :- We are allowed to go only left or down if the row is odd else, we can only go only right or down from current cell.

*/


#include <bits/stdc++.h>
using namespace std;
 
// M x N matrix
#define M 5
#define N 5
 
bool isSafe(int mat[M][N], int i, int j)
{
    if (i < 0 || i >= M || j < 0 || j >= N || mat[i][j] == -1)
        return false;
    
    return true;
}
 
int findMaximum(int mat[M][N], int i, int j)
{
    if (!isSafe(mat, i, j))
        return 0;
 
    if (i & 1)
        return mat[i][j] + max(findMaximum(mat, i, j - 1), 
                            findMaximum(mat, i + 1, j));
 
    else
        return mat[i][j] + max(findMaximum(mat, i, j + 1), 
                        findMaximum(mat, i + 1, j));
}
 
int main()
{
    int mat[M][N] =
    {
        {  1,  1, -1,  1,  1 },
        {  1,  0,  0, -1,  1 },
        {  1,  1,  1,  1, -1 },
        { -1, -1,  1,  1,  1 },
        {  1,  1, -1, -1,  1 }
    };
 
    cout << "Maximum value collected is " << findMaximum(mat, 0, 0);
 
    return 0;
}