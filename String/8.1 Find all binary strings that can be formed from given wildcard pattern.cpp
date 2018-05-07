#include <stdio.h>

// Find all binary strings that can be formed from given 
// wildcard pattern
void printAllCombinations(char pattern[], int i)
{
    if (pattern[i] == '\0')
    {
        printf("%s\n", pattern);
        return;
    }

    // if the current character is '?'
    if (pattern[i] == '?')
    {
        for (int k = 0; k < 2; k++)
        {
            // replace '?' with 0 and 1
            pattern[i] = k + '0';
            
            // recuse for the remaining pattern
            printAllCombinations(pattern, i + 1);
            
            // backtrack (As array is passed by reference to the function)
            pattern[i] = '?';
        }
        return;
    }

    // if the current character is 0 or 1, ignore it and 
    // recuse for the remaining pattern
    printAllCombinations(pattern, i + 1);
}

int main()
{
    char pattern[] = "1?11?00?1?";

    printAllCombinations(pattern, 0);

    return 0;
}