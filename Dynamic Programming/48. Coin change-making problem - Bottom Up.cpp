#include <bits/stdc++.h>
using namespace std;
 
int findMinCoins(int S[], int n, int N)
{
    int T[N + 1];
    T[0] = 0;     
    for (int i = 1; i <= N; i++) 
    {
        T[i] = INT_MAX;
        int res = INT_MAX;
        
        for (int c = 0; c < n; c++)
        {
            if (i - S[c] >= 0)
                res = T[i - S[c]];
 
            if (res != INT_MAX)
                T[i] = min(T[i], res + 1);
        }
    }
 
    return T[N];
}
 
int main()
{
    int S[] = { 1, 2, 3, 4 };
    int n = sizeof(S) / sizeof(S[0]);
    
    int N = 15;
 
    cout << "Minimum number of coins required to get desired change is "
            << findMinCoins(S, n, N);
 
    return 0;
}