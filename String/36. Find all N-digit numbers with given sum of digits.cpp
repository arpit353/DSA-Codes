#include <iostream>
using namespace std;

// Function to find all N-digit numbers with sum of digits equal to sum
// in Bottom-up manner
void findNdigitNums(string res, int n, int sum)
{
	// if number is less than N-digit and its sum of digits is 
    // less than the given sum
    if (n && sum > 0)
    {
    	char d = '0';
    	if (res == "")	// spcl case - number can't start from 0
    		d = '1';
    	
    	// consider every valid digit and put it in the current index
		// and recurse for next index
    	for (; d <= '9'; d++)
	        findNdigitNums(res + d, n - 1, sum - (d - '0'));
    }

    // if number becomes N-digit and its sum of digits is 
    // equal to given sum, print it
    else if (n == 0 && sum == 0)
    	cout << res << " ";
}

int main()
{
    int n = 5;		// N-digit
    int sum = 42;	// given sum
    
	string res;
    findNdigitNums(res, n, sum);

    return 0;
}