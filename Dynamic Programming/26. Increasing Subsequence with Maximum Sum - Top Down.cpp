#include <iostream>
#include <climits>
using namespace std;

/*

Same Problem as previous only change is we are adding the value of array index instead of add 1

*/

int MSIS(int arr[], int n)
{
    int sum[n] = { 0 };
    
    sum[0] = arr[0];
 
    for (int i = 1; i < n; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (sum[i] < sum[j] && arr[i] > arr[j])
                sum[i] = sum[j];
        }
 
        sum[i] += arr[i];
    }
 
    int msis = INT_MIN;
    for (int x : sum)
        msis = max(msis, x);
 
    return msis;
}
 
int main()
{
    int arr[] = { 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "Maximum sum of increasing subsequence is " << 
            MSIS(arr, n);
 
    return 0;
}