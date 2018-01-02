#include <bits/stdc++.h>
using namespace std;
 
#define N 10
 
int lookup[N][2];
 
// Util function to find length of longest alternating subsequence
// if flag is true, next element should be greater
// if flag is false, next element should be smaller
int Util(int arr[], int start, int end, bool flag)
{
    if (lookup[start][flag] == 0)
    {
        int res = 0;
        for (int i = start; i <= end; i++)
        {
            if (flag && arr[i - 1] < arr[i])
                res = max(res, 1 + Util(arr, i + 1, end, !flag));
 
            else if (!flag && arr[i - 1] > arr[i])
                res = max(res, 1 + Util(arr, i + 1, end, !flag));
 
            else
                res = max(res, Util(arr, i + 1, end, flag));
        }
 
        lookup[start][flag] = res;
    }
 
    return lookup[start][flag];
}
 
int findLongestSequence(int arr[], int n)
{
    // Fix first element and recurse for remaining elements.
    // There are two possibilities -
 
    // 1. Next element is greater (pass true)
    // 2. Next element is smaller (pass false)
    return 1 + max(Util(arr, 1, n - 1, true),
                   Util(arr, 1, n - 1, false));
}
 
int main()
{
    int arr[] = { 8, 9, 6, 4, 5, 7, 3, 2, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "The length of Longest Subsequence is " 
            << findLongestSequence(arr, n);
 
    return 0;
}