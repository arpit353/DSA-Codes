#include <bits/stdc++.h>
using namespace std;
 
#define M 5
#define N 5

/*

Given a M x N matrix where each cell has a cost associated with it, find the minimum cost to reach last cell (M-1, N-1) of the matrix from its first cell (0, 0). We can only move one unit right or one unit down from any cell. i.e. from cell (i, j), we can move to (i, j+1) or (i+1, j).

*/


/*

It is straight forward question weare just filling the table by minimimzing the cost by checking the top and left side of the matrix cell.

*/


int findMinCost(int cost[M][N])
{
    int T[M][N];
    
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            T[i][j] = cost[i][j];
            
            if (i == 0 && j > 0)
                T[0][j] += T[0][j - 1];
 
            else if (j == 0 && i > 0)
                T[i][0] += T[i - 1][0];
            
            else if (i > 0 && j > 0)
                T[i][j] += min(T[i - 1][j], T[i][j - 1]);
        }
    }
    
    return T[M - 1][N - 1];
}
 
int main()
{
    int cost[M][N] = 
    {
        { 4, 7, 8, 6, 4 },
        { 6, 7, 3, 9, 2 },
        { 3, 8, 1, 2, 4 },
        { 7, 1, 7, 3, 7 },
        { 2, 9, 8, 9, 3 }
    };
 
    cout << "The minimum cost is " << findMinCost(cost);
 
    return 0;
}