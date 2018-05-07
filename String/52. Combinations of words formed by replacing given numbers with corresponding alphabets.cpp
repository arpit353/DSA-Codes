#include <iostream>
using namespace std;

// Function to find all possible combinations of words formed by replacing
// given positive numbers with corresponding character of English alphabet
void recurse(int digits[], int i, int n, string str)
{
	// base case: all digits are processed in current configuration
	if (i == n)
	{
		// print the string
		cout << str << endl;
		return;
	}

    static string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXVZ";
	int sum = 0;

	// process next two digits (ith and (i+1)th)
	for (int j = i; j <= min(i + 1, n - 1); j++)
	{
		sum = (sum * 10) + digits[j];

		// if a valid character can be formed by taking one or both digits,
		// append it to the output and recurse for remaining digits
		if (sum <= 26)
			recurse(digits, j + 1, n, str + alphabet[sum - 1]);
	}
}

// main function
int main()
{
	int digits[] = { 1, 2, 2 };
	int n = sizeof(digits)/sizeof(digits[0]);

	string str;
	recurse(digits, 0, n, str);

	return 0;
}
