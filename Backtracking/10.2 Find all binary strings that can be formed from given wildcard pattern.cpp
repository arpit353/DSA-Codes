#include <iostream>
#include <stack>
using namespace std;

/*

We can also solve this problem iteratively using stack, queue, set, vector or any other container. The idea remains the same. We start by processing each character of the pattern one by one but instead of recursing for the remaining pattern, we push it to a container. At each iteration, we pop a string from container, find first occurrence of wildcard pattern ‘?’ in it, replace ‘?’ with 0 & 1 and finally push it back to the container. If no wildcard pattern is found, print the popped string. We repeat this process until the container is empty.

*/

/*

we replace the ? with all the possible characters and push it in the stack. Then find the next ? and replace them with all possible ways. In this way we can find all the possible wild card combinations.

*/


// Find all binary strings that can be formed from given 
// wildcard pattern
void printAllCombinations(string pattern)
{
    // create an empty stack (we can also use set, queue, vector 
    // or any other container)
    stack<string> list;
    list.push(pattern);        // push the pattern into the stack

    size_t index;
 
    // do till stack is not empty
    while (!list.empty())
    {
        // pop string from stack and process it
        string curr = list.top();
        list.pop();

        // index stores position of first occurrence of wildcard 
        // pattern in curr
        if ((index = curr.find_first_of('?')) != string::npos)
        {
            for (int i = 0; i < 2; i++)
            {
                // replace '?' with 0 and 1 and push it to the stack
                curr[index] = i + '0';
                list.push(curr);
            }
        }
        
        // If no wildcard pattern is found, print the string
        else
            cout << curr << endl;
    }
}

int main()
{
    string str = "1?11?00?1?";
 
    printAllCombinations(str);
 
    return 0;
}