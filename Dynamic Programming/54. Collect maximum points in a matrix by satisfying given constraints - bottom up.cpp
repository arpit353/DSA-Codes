#include <bits/stdc++.h>
using namespace std;
 
#define M 5
#define N 5

int findMaximum(int mat[M][N])
{
    int T[M+1][N+1];
    memset(T, 0, sizeof T);
 
    for (int i = 1; i<= M; i++)
    {
        if (i & 1)
        {
            for (int j = 1; j <= N; j++)
            {
                if (mat[i-1][j-1] == -1)
                    T[i][j] = 0;
                else
                    T[i][j] = mat[i-1][j-1] + max(T[i][j-1], T[i-1][j]);
            }
        }
        else
        {
            for (int j = N; j >= 1; j--)
            {
                if (mat[i-1][j-1] == -1)
                    T[i][j] = 0;
                else
                    T[i][j] = mat[i-1][j-1] + max(T[i][j+1], T[i-1][j]);
            }
        }
    }
 
    
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << T[i][j] << " ";
        cout << endl;
 
    int i = 1, j =1;
    int res = T[i][j];
 
    while (i <= M && j >= 0 && j <= N)
    {
        if (T[i][j] == T[i+1][j] || T[i][j] + 1 == T[i+1][j])
            i++;
        else if (T[i][j] == T[i][j+1] || T[i][j] + 1 == T[i][j+1])
            j++;
        else if (T[i][j] == T[i][j-1] || T[i][j] + 1 == T[i][j-1])
            j--;
        else
            break;
 
        res = T[i][j];
    }
    
    /*
    
    1 2 0 1 2 
    3 2 0 0 3 
    4 5 6 7 0 
    0 0 9 8 1 
    1 2 0 0 2 
    Maximum value collected is 9
    
    We can see from the output that in the maximum sequence the value of inner elements is increasing because that's what we did while filling up the table.
    
    
    */
    
 
    return res;
}
 
// main function
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
 
    cout << "Maximum value collected is " << findMaximum(mat);
 
    return 0;
}