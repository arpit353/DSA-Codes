#include <iostream>
#include <stack>
using namespace std;

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