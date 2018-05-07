#include <iostream>
using namespace std;

// Function to find all N-digit strictly increasing 
// numbers in Top-down manner
void strictlyInc(string res, int n, char curr)
{
    if (n) {
    	// start from previous digit (last digit was next)
    	for (char ch = curr; ch >= '1'; ch--)
	        strictlyInc(ch + res, n - 1, ch - 1);
    }
    // If the string becomes N-digit, print it
    else 
    	cout << res << " ";
}

int main()
{
    int n = 7;
	string res ="";
	
    strictlyInc(res, n, '9');

    return 0;
}