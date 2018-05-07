#include <iostream>
using namespace std;

// Function to find maximum length of substring with equal sum 
// of left and right half
int longestPalindrome(string str)
{
	int n = str.length();

	// sum[i] stores sum of digits of substring[0..i-1]
	int sum[n + 1] = {0};

	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + (str[i - 1] - '0');	// '0' is subtracted to 
													// convert char to integer

	// stores maximum length of substring with equal sum 
	// of left and right half
	int max = 0;

	// consider even length substring from index [i to j]
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = i + 1; j < n; j += 2) 
		{
			// calculate length of the substring
			int range = j - i + 1;
			
			// find middle index of the substring
			int mid = i + range / 2;

			// if sum of left half and right half is same and length of substring
			// is more than maximum length found so far
			if ((sum[mid] - sum[i] == sum[j + 1] - sum[mid]) && max < range)
				max = range;
		}
	}
	
	return max;
}

int main()
{
	string str = "13267224";

	cout << "Longest length of palidromic sum substring is " 
			<< longestPalindrome(str);

	return 0;
}
