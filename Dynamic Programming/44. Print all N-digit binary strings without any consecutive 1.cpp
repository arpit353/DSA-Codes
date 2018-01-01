#include <iostream>
using namespace std;

/*

In this we are recursivly calling the count string function. we can call the function for 0 anytime but we can call for 1 only when last digit was 0. If we reach the end we print the string. 

*/

void countStrings(int n, string out, int last_digit)
{
    if (n == 0)
    {
        cout << out << endl;
        return;
    }
 
    countStrings(n - 1, out + "0", 0);
    
    if (last_digit == 0)
        countStrings(n - 1, out + "1", 1);
}
 
int main()
{
    int n = 5;
    string out = "";
    
    countStrings(n, out, 0);
 
    return 0;
}
 