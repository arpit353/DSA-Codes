/*

For a given pattern[0..m] and str[0..n],

If pattern[m] == ‘*’, if ‘*’ matches with current character in input string we will move to next character in the string else we ignore ‘*’ and move to next character in the pattern.
 
If pattern[m] == ‘?’, we ignore current characters of both string and pattern and check if pattern[0..m-1] matches str[0..n-1]
 
If the current character in pattern is not a wildcard character, it should match with current character in the input string
 
Special care has to be taken to handle base conditions:

If both input string and pattern reaches their end, we return true.
 
If only pattern reaches its end, we return false.
 
If only input string reaches its end, return true only if remaining characters in the pattern are all ‘*’

*/

/*

To solve this question we will use recursion and check the string from the last. There can be 3 cases

i) If the string character is * then if will check both condition, if the * letter is ignored and second if we match it. We can match it by reducing the string but keeping constant the pattern string.

ii) If string character is not ? and it does not match then then it return false

iii) If it is ? or it matches then make it match the string by decreasing both string length.

*/


#include <bits/stdc++.h>
using namespace std;
#define LEN 20
 
int lookup[LEN][LEN];
 
bool isMatching(char str[], char pattern[], int n, int m)
{
    if (m < 0 && n < 0)
        return true;
    
    else if (m < 0)
        return false;
    
    else if (n < 0) 
    {
        for (int i = 0; i <= m; i++)
            if (pattern[i] != '*')
                return false;
 
        return true;
    }
    
    if (lookup[m][n] == -1) 
    {
        if (pattern[m] == '*') 
        {
            lookup[m][n] = isMatching(str, pattern, n - 1, m) || 
                        isMatching(str, pattern, n, m - 1);
        }
        else 
        {
            if (pattern[m] != '?' && pattern[m] != str[n])
                lookup[m][n] = false;
            
            else
                lookup[m][n] = isMatching(str, pattern, n - 1, m - 1);
        }
    }
    
    return lookup[m][n];
}
 
int main()
{
    char str[] = "xyxzzxy";
    char pattern[] = "x***x?";
 
    memset(lookup, -1, sizeof(lookup));
 
    if (isMatching(str, pattern, strlen(str) - 1, strlen(pattern) - 1))
        cout << "Match" << endl;
    else
        cout << "No Match" << endl;
 
    return 0;
}