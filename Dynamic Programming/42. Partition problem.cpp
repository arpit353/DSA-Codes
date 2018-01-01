/*

Given a set of positive integers, find if it can be divided into two subsets with equal sum.

For example,
S = {3,1,1,2,2,1},

We can partition S into two partitions each having sum 5.

S1 = {1,1,1,2}
S2 = {2,3}.

Note that this solution is not unique. Below is another solution.

S1 = {3,1,1}
S2 = {2,2,1}

*/

/*

Partition problem is special case of Subset Sum Problem which itself is a special case of the Knapsack Problem. The idea is to calculate sum of all elements in the set. If sum is odd, we can’t divide the array into two sets. If sum is even, we check if subset with sum/2 exists or not. 

We are checking if there is a subset with sum/2 sum and if it is present and the other elements of the array which are not part of subset sums to sum/2. Similar to knapsack we include a term in the matrix by subtracting tht element value from the sum and exclude the element by just passing the sum in the remaining array without last element.   

*/


#include <iostream>
using namespace std;
 
bool subsetSum(int arr[], int n, int sum)
{
    if (sum == 0)
        return true;
 
    if (n < 0 || sum < 0)
        return false;
 
    bool include = subsetSum(arr, n - 1, sum - arr[n]);
    
    bool exclude = subsetSum(arr, n - 1, sum);
    
    return include || exclude;
}
 
bool partition(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
       sum += arr[i];
    
    return !(sum & 1) && subsetSum(arr, n, sum/2);
}
 
int main()
{
    int arr[] = { 7, 3, 1, 5, 4, 8 };
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    if (partition(arr, n))
        cout << "Yes";
    else
        cout << "No";
 
    return 0;
}