#include <iostream>
#include <climits>
using namespace std;

/*

In this code we have to print longest increasing subsequence length. So here is top down approach.

For every letter of the string, check all the letters which are behind the letter and check if it is smaller than the current letter and its LIS value is larger than then current. We do this so that we can get the LIS value of just smaller element from the current letter and add one to it. This sums up the whole idea about the question.  

*/
int LIS(int arr[], int n)
{
    int L[n] = { 0 };
    
    L[0] = 1;
 
    for (int i = 1; i < n; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (arr[j] < arr[i] && L[j] > L[i])
                L[i] = L[j];
        }
 
        L[i]++;
    }
    
    int lis = INT_MIN;
    for (int x : L)
        lis = max(lis, x);
 
    return lis;
}
 
int main()
{
    int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "Length of LIS is " << LIS(arr, n);
 
    return 0;
}