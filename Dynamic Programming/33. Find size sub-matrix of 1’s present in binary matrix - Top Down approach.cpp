#include <bits/stdc++.h>
using namespace std;
 
#define M 8
#define N 6
 
int findLargestSquare(int mat[M][N], int m, int n, int &max_size)
{
    if (m == 0 || n == 0 || mat[m][n] == 0)
        return mat[m][n];
 
    int left = findLargestSquare(mat, m, n - 1, max_size);
 
    int top = findLargestSquare(mat, m - 1, n, max_size);
    
    int top_left = findLargestSquare(mat, m - 1, n - 1, max_size);
    
    int size = 1 + min (min(top, left), top_left);
 
    max_size = max(max_size, size);
 
    return size;
}
 
int main()
{
    int mat[M][N] = 
    { 
        { 0, 0, 1, 0, 1, 1 },
        { 0, 1, 1, 1, 0, 0 },
        { 0, 0, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1, 1 }, 
        { 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1 }
    };
     
    int size = 0;
    
    findLargestSquare(mat, M-1, N-1, size);
    
    cout << "The size of largest square sub-matrix of 1's is " << size;
    
    return 0;
}