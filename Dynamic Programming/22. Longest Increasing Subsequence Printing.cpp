#include <bits/stdc++.h>
using namespace std;

/*

Similar to finding the length of LIS but in this we are adding letters to the string not incresing the length of string.

*/

void findLIS(int arr[], int n)
{
    LIS[0].push_back(arr[0]);
 
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && LIS[j].size() > LIS[i].size())
                LIS[i] = LIS[j];
        }
 
        LIS[i].push_back(arr[i]);
    }
 
    for (int i = 0; i < n; i++)
    {
        cout << "LIS[" << i << "] - ";
        for (int j : LIS[i])
            cout << j << " ";
        cout << endl;
    } 
    
    int j = 0;
    for (int i = 0; i < n; i++)
        if (LIS[j].size() < LIS[i].size())
            j = i;
 
    for (int i : LIS[j])
        cout << i << " ";
}
 
int main()
{
    int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    int n = sizeof(arr)/sizeof(arr[0]);
 
    findLIS(arr, n);
 
    return 0;
}