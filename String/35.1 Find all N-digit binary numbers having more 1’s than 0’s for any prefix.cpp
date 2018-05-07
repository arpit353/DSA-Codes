#include <iostream>
using namespace std;

// Function to find all N-digit binary numbers having 
// more 1's than 0's at any position
void find(string str, int n, int zeros, int ones)
{
	// continue only if number of ones are more than equal
	// to number of zeroes
	if (ones < zeros)
		return;
	
	// if number becomes N-digit, print it
	if (n == 0)
	{
		cout << str << endl;
		return;
	}
	
	// append 1 to the result and recuse with one less digit
	find(str + "1", n - 1, zeros, ones + 1);

	// append 0 to the result and recuse with one less digit
	find(str + "0", n - 1, zeros + 1, ones); 
}

int main()
{
	// given number of digits
	int n = 4;

	string str;
	find(str, n, 0, 0);
	
	return 0;
}