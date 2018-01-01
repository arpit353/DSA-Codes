#include <bits/stdc++.h>
using namespace std;
 
#define M 4
#define N 4
 
unordered_map<string, int> lookup;

/*

Quite straight forward we check all possible routes by subtracting the cost and check the matrix for the adjacent cell in the matrix. if we get to exact 0 cost anywhere we retrun 1. That mean we have got to the required destination.

*/

int countPaths(int mat[][N], int m, int n, int cost)
{
    if (cost < 0)
        return 0;
 
    if (m == 0 && n == 0)
    {
        if (mat[0][0] - cost == 0)
            return 1;
        else 
            return 0;
    }
 
    string key = to_string(m) + "|" + to_string(n) + "|" + to_string(cost);
    
    if (lookup.find(key) == lookup.end())
    {
        if (m == 0)
            lookup[key] = countPaths(mat, 0, n - 1, cost - mat[m][n]);
        
        else if (n == 0)
            lookup[key] = countPaths(mat, m - 1, 0, cost - mat[m][n]);
        
        else
            lookup[key] = countPaths(mat, m - 1, n, cost - mat[m][n]) + 
                countPaths(mat, m, n - 1, cost - mat[m][n]);
    }
 
    return lookup[key];
}
 
int main()
{
    int mat[M][N] = 
    { 
        { 4, 7, 1, 6 },
        { 5, 7, 3, 9 },
        { 3, 2, 1, 2 },
        { 7, 1, 6, 3 }
    };
 
    int cost = 25;
 
    cout << "Total paths with cost " << cost << " are " << 
            countPaths(mat, M-1, N-1, cost);
 
    return 0;
}