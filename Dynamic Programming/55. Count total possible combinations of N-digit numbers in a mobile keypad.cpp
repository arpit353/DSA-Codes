#include <bits/stdc++.h>
using namespace std;

/*

Given a mobile keypad having digits from [0-9] associated with each key, count total possible combinations of digits having length n. We can start with any digit and press only four adjacent keys of any digit. Keypad also contains * and # key which we are not allowed to press.

*/

#define N 8
 
int lookup[10][N];
 
// Below arrays details all 4 possible movements from current cell
int row[] = { 0, -1, 0, 1 };
int col[] = { -1, 0, 1, 0 };
 
// The function returns false if (i, j) is not a valid position
int isValid(int i, int j)
{
    // for handling '*' or '#' (present in 4th row and 1st & 3rd column)
    if (i == 3 && (j == 0 || j == 2))
        return 0;
 
    return (i >= 0 && i <= 3 && j >= 0 && j <= 2);
}
 
void fillMap(multimap<int, int>& mp)
{
    // mobile keypad
    char key[4][3] = 
    {
        { '1', '2', '3' },
        { '4', '5', '6' },
        { '7', '8', '9' },
        { '*', '0', '#' } 
    };
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // move in all four possible directions of current 
            // digit key[i][j]
            for (int k = 0; k < 4; k++) 
            {
                int r = i + row[k];
                int c = j + col[k];
                
                // insert adjacent cell to multimap if valid
                if (isValid(i, j) && isValid(r, c))
                    mp.insert(make_pair(key[i][j] - '0', key[r][c] - '0'));
            }
        }
    }
}
 

/*

The table we filled contain the element as the key and what all are the possibility of theat digit. n here is the distance which can be travelled from the base digit to. Suppose we have to find all possibilities of length 3 then we can ckeck 3 different keys. First we traverse current key then the key which is adjustant and then the keys which are adjusant to the adjacent. In this way we will move 3 steps.

*/

int getCount(multimap<int, int> keypad, int i, int n)
{
    if (n == 1) // reached end of digit
        return 1;
 
    // if sub-problem is seen for the first time, solve it and 
    // store its result in a array
    if (lookup[i][n] == 0) 
    {
        // recurse for remaining length
        lookup[i][n] = getCount(keypad, i, n - 1);
 
        // recur for all digits reachable from i
        for (auto it = keypad.find(i); 
            (it != keypad.end() && it->first == i); it++)
            lookup[i][n] += getCount(keypad, it->second, n - 1);
    }
 
    return lookup[i][n];
}
 
int main()
{
    int n = 2;
    
    multimap<int, int> keypad;
    fillMap(keypad);
    
    int count = 0;
    for (int i = 0; i <= 9; i++)
        count += getCount(keypad, i, n);
 
    cout << "Total possible combinations are " << count;
 
    return 0;
}