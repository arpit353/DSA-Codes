#include <iostream>
using namespace std;

// Function to find all N-digit strictly increasing 
// numbers in Bottom-up manner
void strictlyInc(string res, int n, char prev)
{
    if (n) {
    	// start from next digit (last digit is prev)
    	for (char ch = prev + 1; ch <= '9'; ch++)
	        strictlyInc(res + ch, n - 1, ch);
    }
    // If the string becomes N-digit, print it
    else 
    	cout << res << " ";
}

int main()
{
    int n = 7;
	string res;
	
    strictlyInc(res, n, '0');

    return 0;
}