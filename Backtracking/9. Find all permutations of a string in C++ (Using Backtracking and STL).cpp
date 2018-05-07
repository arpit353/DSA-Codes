#include <iostream>
using namespace std;

/*
In this post, we will see how to find all permutations of a string containing all distinct characters in C++.

For example, string ABC has 6 permutations. i.e. ABC, ACB, BAC, BCA, CBA, CAB

Approach : (Using Backtracking) –

We can in-place find all permutations of a given string by using Backtracking. The idea is to swap each of the remaining characters in the string with its first character and then find all the permutations of the remaining characters using a recursive call. The base case of the recursion is when the string is left with only one unprocessed element. Below is the recursion tree for printing all permutations of string “ABC”.

*/

/*

To implement the case where no swap happen, we have started the for loop from i not i+1.

*/


// Function to find all Permutations of a given string str[i..n-1]
// containing all distinct characters
void permutations(string str, int i, int n)
{
    // base condition
    if (i == n - 1)
    {
        cout << str << endl;
        return;
    }

    // process each character of the remaining string
    for (int j = i; j < n; j++)
    {
        // swap character at index i with current character
        swap(str[i], str[j]);        // STL swap() used

        // recurse for string [i+1, n-1]
        permutations(str, i + 1, n);

        // backtrack (restore the string to its original state)
        swap(str[i], str[j]);
    }
}

// Find all Permutations of a string
int main()
{
    string str = "ABC";

    permutations(str, 0, str.length());

    return 0;
}