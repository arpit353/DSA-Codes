#include <bits/stdc++.h>
using namespace std;

/*

We have to print longest increasing subsequence so thats why we make an array of lists for every letter. Same concept which we implemented during finding length the only difference is insetad of adding 1 to the maximum length of subarray we take the list of sub array and push back the last letter in the end.  

*/

void findLIS(int arr[], int n)
{
    vector<int> LIS[n];
 
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