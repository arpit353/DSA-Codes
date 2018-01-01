#include <bits/stdc++.h>
using namespace std;
 
#define MAX 10
 
int lookup[MAX][MAX];
 
/*

Matrix chain multiplication (or Matrix Chain Ordering Problem, MCOP) is an optimization problem that to find the most efficient way to multiply given sequence of matrices. The problem is not actually to perform the multiplications, but merely to decide the sequence of the matrix multiplications involved.
 
The matrix multiplication is associative as no matter how the product is parenthesized, the result obtained will remain the same. For example, for four matrices A, B, C, and D, we would have

((AB)C)D = ((A(BC))D) = (AB)(CD) = A((BC)D) = A(B(CD))

However, the order in which the product is parenthesized affects the number of simple arithmetic operations needed to compute the product, or the efficiency. For example, if A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix, then

computing (AB)C needs (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations

while computing A(BC) needs (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations

Clearly the first method is more efficient.

*/

/*

This code we have a dimension array and the start and end of the array. So what we do in this question is we take all possible splits that can take place in the array. Then we add the cost of that split and recursively find the cost in the left and right sub array.

Also we fill the minimum value in the matrix that's why we get the minimum cost every time.

*/


int MatrixChainMultiplication(int dims[], int i, int j)
{
    if (j <= i + 1)
        return 0;
 
    int min = INT_MAX;
    
    if (lookup[i][j] == 0) 
    {
        for (int k = i + 1; k <= j - 1; k++) 
        {
            int cost = MatrixChainMultiplication(dims, i, k);
            
            cost += MatrixChainMultiplication(dims, k, j);
            
            cost +=    dims[i] * dims[k] * dims[j];
 
            if (cost < min)
                min = cost;
        }
        lookup[i][j] = min;
    }
 
    return lookup[i][j];
}
 
int main()
{
    int dims[] = { 10, 30, 5, 60 };
    int n = sizeof(dims) / sizeof(dims[0]);
 
    cout << "Minimum cost is " << MatrixChainMultiplication(dims, 0, n - 1);
    
    return 0;
}