#include <bits/stdc++.h>
using namespace std;
 
int dist(string X, int m, string Y, int n)
{
    int T[m + 1][n + 1];
 
    memset(T, 0, sizeof(T));
 
    // source prefixes can be transformed into empty string by
    // dropping all characters
    for (int i = 1; i <= m; i++)
        T[i][0] = i;                // (case 1)
 
    // target prefixes can be reached from empty source prefix
    // by inserting every character
    for (int j = 1; j <= n; j++)
        T[0][j] = j;                // (case 1)
 
    int substitutionCost;
 
    for (int i = 1; i <= m; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (X[i - 1] == Y[j - 1])                // (case 2)
                substitutionCost = 0;                // (case 2)
            else
                substitutionCost = 1;                // (case 3c)
 
            T[i][j] = min(min(T[i - 1][j] + 1,        // deletion (case 3b)
                              T[i][j - 1] + 1),        // insertion (case 3a)
                T[i - 1][j - 1] + substitutionCost);// replace (case 2 & 3c)
        }
    }
 
    return T[m][n];
}
 
int main()
{
    string X = "kitten", Y = "sitting";
 
    cout << "The Levenshtein Distance is " << 
        dist(X, X.length(), Y, Y.length());
 
    return 0;
}


/*

The Levenshtein distance between two words is the minimum number of single-character edits (i.e. insertions, deletions or substitutions) required to change one word into the other. Each of these operations has unit cost.
 

For example, the Levenshtein distance between kitten and sitting is 3. A minimal edit script that transforms the former into the latter is:

kitten -> sitten (substitution of s for k)
sitten -> sittin (substitution of i for e)
sittin -> sitting (insertion of g at the end)

  
The Edit distance problem has an optimal substructure. That means the problem can be broken down into smaller, simple “subproblems”, which can be broken down into yet simpler subproblems, and so on, until, finally, the solution becomes trivial.
 

Problem: Convert string X[1..m] to Y[1..n] by performing edit operations on string X.

Sub-problem: Convert substring X[1..i] to Y[1..j] by performing edit operations on substring X.
 

CASE 1: We have reached the end of either substring

If substring X is empty, then we insert all remaining characters of substring Y to X and the cost of this operation is equal to number of characters left in substring Y.

(”, ‘ABC’) –> (‘ABC’, ‘ABC’) (cost = 3)

If substring Y is empty, then we delete all remaining characters of X to convert it into substring Y. The cost of this operation is equal to number of characters left in substring X.

(‘ABC’, ”) –> (”, ”) (cost = 3)

 

CASE 2: Last characters of substring X and substring Y are same

If last characters of substring X and substring Y matches, nothing needs to be done. We simply recurse for remaining substring X[0..i-1], Y[0..j-1]. As no edit operation is involved, the cost will be 0.

(‘ACC‘, ‘ABC‘) –> (‘AC’, ‘AB’) (cost = 0)

 

CASE 3: Last characters of substring X and substring Y are different

If the last characters of substring X and substring Y are different, then we return minimum of below three operations –
 

Insert last character of Y to X. The size of Y reduces by 1 and size of X remains the same. This accounts for X[1..i], Y[1..j-1] as we move in on target substring, but not in source substring.

(‘ABA‘, ‘ABC‘) –> (‘ABAC‘, ‘ABC‘) ==  (‘ABA’, ‘AB’) (using case 2)

 

Delete last character of X. The size of X reduces by 1 and size of Y remains the same. This accounts for X[1..i-1], Y[1..j] as we move in on source string, but not in target string.

(‘ABA‘, ‘ABC‘) –> (‘AB’, ‘ABC’)

 

Substitute (Replace) current character of X by current character of Y. The size of both X and Y reduces by 1. This accounts for X[1..i-1], Y[1..j-1] as we move in both source string and target string.

(‘ABA‘, ‘ABC‘) – > (‘ABC’, ‘ABC’)  == (‘AB’, ‘AB’)  (using case 2)

It is basically same as case 2 where the last two characters matches and we move in both source string and target string except it costs an edit operation.

 
So we can define the problem recursively as –


             | max(i, j)                       when min(i, j) = 0
             
dist[i][j] = | dist[i – 1][j – 1]              when X[i-1] == Y[j-1]
             
             | 1 + minimum { dist[i – 1][j],   when X[i-1] != Y[j-1]
             |               dist[i][j – 1],
             |               dist[i – 1][j – 1] }



*/
