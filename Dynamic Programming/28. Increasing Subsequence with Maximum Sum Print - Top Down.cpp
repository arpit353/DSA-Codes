#include <bits/stdc++.h>
using namespace std;

/*

Same code as previous just we are storing the whole list of numbers not just the sum or count

*/

void printMSIS(int arr[], int n)
{
    vector<int> MSIS[n];
    MSIS[0].push_back(arr[0]);
 
    int sum[n] = { 0 };
    sum[0] = arr[0];
 
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
 
            if (sum[i] < sum[j] && arr[i] > arr[j])
            {
                MSIS[i] = MSIS[j];      
                sum[i] = sum[j];        
            }
        }
        
        MSIS[i].push_back(arr[i]);
 
        sum[i] += arr[i];
    }
 
    for (int i = 0; i < n; i++)
    {
        cout << "MSIS[" << i << "] - ";
        for (int j : MSIS[i])
            cout << j << " ";
        cout << endl;
    }
 
    int j = 0;
    for (int i = 1; i < n; i++)
        if (sum[i] > sum[j])
            j = i;
 
    for (int i : MSIS[j])
        cout << i << " ";
}
 
int main()
{
    int arr[] = { 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    printMSIS(arr, n);
 
    return 0;
}
 