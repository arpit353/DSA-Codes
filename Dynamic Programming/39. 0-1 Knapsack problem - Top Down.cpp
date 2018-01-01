#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;
 
unordered_map<string, int> lookup;

/*

In 0-1 Knapsack problem, we are given a set of items, each with a weight and a value and we need to determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.

*/

/*

Simply start from the end of the array. And check both possibility of including the last element and excluding the last element of the array. We include the last element by subtractig the weight we have to make. We exclude the element by simply passing the normal weight in the fuction with decreased array.  

*/

int knapSack(int v[], int w[], int n, int W)
{
    if (W < 0)
        return INT_MIN;
    
    if (n < 0 || W == 0)
        return 0;
 
    string key = to_string(n) + "|" + to_string(W);
    
    if (lookup.find(key) == lookup.end())
    {
        int include = v[n] + knapSack(v, w, n - 1, W - w[n]);
        
        int exclude = knapSack(v, w, n - 1, W);
        
        lookup[key] = max (include, exclude);
    }
    
    return lookup[key];
}
 
int main()
{
    int v[] = { 20, 5, 10, 40, 15, 25 };
    int w[] = {  1, 2,  3,  8,  7, 4 };
    
    int W = 10;
 
    int n = sizeof(v) / sizeof(v[0]);
 
    cout << "Knapsack value is " << knapSack(v, w, n - 1, W);
 
    return 0;
}