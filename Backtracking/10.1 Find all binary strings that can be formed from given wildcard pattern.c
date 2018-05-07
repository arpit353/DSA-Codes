#include <stdio.h>

/*
Given a binary pattern that contains ‘?’ wildcard character at few positions, find all possible combinations of binary strings that can be formed by replacing the wildcard character by either 0 or 1.

For example, for wildcard pattern 1?11?00?1?, the possible combinations are

1011000010
1011000011
1011000110
1011000111
1011100010
1011100011
1011100110
1011100111
1111000010
1111000011
1111000110
1111000111
1111100010
1111100011
1111100110
1111100111

Recursive solution –
We can easily solve this problem using recursion. The idea is to process each character of the pattern one by one and recurse for the remaining pattern. If the current digit is 0 or 1, we ignore it and if the current character is a wildcard character ‘?’, we replace it with 0 & 1 and recurse for the remaining pattern.

*/


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