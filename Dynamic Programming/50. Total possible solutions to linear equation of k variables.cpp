/*
Given a linear equation of k variables, count total number of possible solutions of it.

For example,

Input: coeff = {1, 3, 5, 7}, rhs = 8
 
Output: Total number of solutions are 6

Above input represents the equation a + 3b + 5c + 7d = 8.

( a = 1, b = 0, c = 0, d = 1 )
( a = 0, b = 1, c = 1, d = 0 )
( a = 2, b = 2, c = 0, d = 0 )
( a = 3, b = 0, c = 1, d = 0 )
( a = 5, b = 1, c = 0, d = 0 )
( a = 8, b = 0, c = 0, d = 0 )
 
Input: coeff = {1, 2, 3}, rhs = 4
 
Output: Total number of solutions are 4

Above input represents the equation x + 2y + 3z = 4.

( x = 1, y = 0, z = 1 )
( x = 0, y = 2, z = 0 )
( x = 2, y = 1, z = 0 )
( x = 4, y = 0, z = 0 )

*/

/*

The problem is similar to finding total number of ways to get the denomination of coins. Here, coefficients of an equation can be considered as coins denominations and RHS of an equation can be considered as desired change. Let us begin by recursively defining the problem –

count(coeff, k, rhs) = count(coeff, k, rhs-coeff[k]) + count(coeff, k-1, rhs);
That is, for each coefficient of a variable

We include current coefficient coeff[k] in solution and recurse with remaining value (rhs-coeff[k]).
 
We exclude current coefficient coeff[k] from solution and recurse for remaining coefficients (k-1).

*/

#include <iostream>
#include <unordered_map>
using namespace std;
 
unordered_map<string, int> lookup;
 
int count(int coeff[], int k, int rhs)
{
    if (rhs == 0)
        return 1;
 
    if (rhs < 0 || k < 0)
        return 0;
 
    string key = to_string(k) + "|" + to_string(rhs);
 
    if (lookup.find(key) == lookup.end())
    {
        int include = count(coeff, k, rhs - coeff[k]); // case 1 
 
        int exclude = count(coeff, k - 1, rhs); // case 2
 
        lookup[key] = include + exclude;
    }
 
    return lookup[key];
}
 
int main()
{
    int coeff[] = { 1, 2, 3 };
    int k = sizeof(coeff) / sizeof(coeff[0]);
 
    int rhs = 4;
 
    cout << "Total number of solutions are " << count(coeff, k - 1, rhs);
 
    return 0;
}

