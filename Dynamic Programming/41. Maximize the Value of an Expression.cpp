/*

Given an array A, maximize value of the expression (A[s] – A[r] + A[q] – A[p]) where p, q, r and s are indices of the input array and s > r > q > p.

*/

/*

We can use Dynamic Programming to solve this problem. The idea is to create four lookup tables L1[], L2[], L3[] and L4[] where –

L1[] stores the maximum value of A[s]
L2[] stores the maximum value of A[s] – A[r]
L3[] stores the maximum value of A[s] – A[r] + A[q]
L4[] stores the maximum value of A[s] – A[r] + A[q] – A[p]

*/

/*

In this code we have to maximize the expression value and also take care of the condition that s > r > q > p. To satisfy this condition only we are traversing in the backward direction and saving the maximum element till then in the position. That's why first we made the array and fill the value from the end (the maximum till then). Then we make next iteration from one step backward and try to makimize the result of previous iteration.

and in this way we get the result of maximizing the expression.

*/

#include <bits/stdc++.h>
using namespace std;
 
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    cout << endl;
}
 
int maximizeExpression(int A[], int n)
{
    int L1[n + 1], L2[n], L3[n - 1], L4[n - 2];
    
    for (int i = 0; i <= n - 3; i++)
        L1[i] = L2[i] = L3[i] = L4[i] = INT_MIN;
 
    L1[n - 2] = L2[n - 2] = L3[n - 2] = INT_MIN;
    L1[n - 1] = L2[n - 1] = L1[n] = INT_MIN;
 
    for (int i = n - 1; i >= 0; i--)
        L1[i] = max(L1[i + 1], A[i]);
 
    for (int i = n - 2; i >= 0; i--)
        L2[i] = max(L2[i + 1], L1[i + 1] - A[i]);
 
    for (int i = n - 3; i >= 0; i--)
        L3[i] = max(L3[i + 1], L2[i + 1] + A[i]);
 
    for (int i = n - 4; i >= 0; i--)
        L4[i] = max(L4[i + 1], L3[i + 1] - A[i]);
 
    return L4[0];
}
 
int main()
{
    int A[] = { 3, 9, 10, 1, 30, 40 };
    int n = sizeof(A) / sizeof(A[0]);
 
    if (n >= 4)
        cout << maximizeExpression(A, n);
 
    return 0;
}