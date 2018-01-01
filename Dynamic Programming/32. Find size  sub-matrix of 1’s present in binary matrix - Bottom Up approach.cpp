#include <iostream>
using namespace std;
 
#define M 8
#define N 6

/*

This is bottom up approach.

In this question we are finding the largest square with all 1. So for that we will use the concept that in any matrix if we check the last element of the matrix(corner one) it will have square of one less dimension. In a 2*2 matrix last element will have 1,1 square matrix in the the matrix. In 3*3 matrix, we will have 2*2 matrix on all top,left and top-left. Thats why we will recursively check for the smaller matrix from the top, left and top-left.   

*/

int findLargestSquare(int mat[M][N])
{
    int lookup[M][N];
 
    int max = 0;

    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            lookup[i][j] = mat[i][j];
            
            if (i && j && mat[i][j])
            
            lookup[i][j] = min (min (lookup[i][j - 1], lookup[i - 1][j]),
                                    lookup[i - 1][j - 1]) + 1;
 
            if (max < lookup[i][j])
                max = lookup[i][j];
        }
    }
    
    return max;
}
 
int main()
{
    // input boolean matrix
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
 
    cout << "The size of largest square sub-matrix of 1's is " << 
            findLargestSquare(mat);
 
    return 0;
}