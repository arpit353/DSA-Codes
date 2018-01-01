#include <iostream>
#include <climits>
using namespace std;

/*

In this code we have to find LIS using recursion. In this prev means last element of the sequence. while traversal we have 2 option weather to include the letter or not. We find the LIS while excluding the letter. That we did by checking lis of next elemet with same prev. If it is greater than the prev then only we will check for inclusion by passing arr[i] as prev in next element and ad d 1 to it.

*/

int LIS(int arr[], int i, int n, int prev)
{
    if (i == n)
        return 0;
 
    int excl = LIS(arr, i + 1, n, prev);
 
    int incl = 0;
    if (arr[i] > prev)
        incl = 1 + LIS(arr, i + 1, n, arr[i]);
 
    return max(incl, excl);
}
 
int main()
{    
    int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Length of LIS is " << LIS(arr, 0, n, INT_MIN);
 
    return 0;
}