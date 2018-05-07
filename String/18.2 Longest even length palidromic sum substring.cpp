#include <iostream>
#include <unordered_set>
using namespace std;

// expand in both directions of low and high to find 
// maximum length palindrome
void expand(string str, int low, int high, int &max)
{
	int len = str.length();
	int leftsum = 0, rightsum = 0;
	
	while (low >= 0 && high < len) 
	{
		// update sum of left half and right half
		leftsum += str[low] - '0';
		rightsum += str[high] - '0';
		
		// update maximum length of palindrome if sum of left half 
		// becomes same as sum of the right half
		if (leftsum == rightsum && (high - low + 1) > max)
			max = high - low + 1;
	
		// expand in both directions
		low--, high++;
	}
}

// Function to find maximum length of substring with equal 
// sum of left and right half
int longestPalindrome(string str, int n)
{
	// stores maximum length of substring with equal sum 
	// of left and right half
	int max = 0;

	// an even length palindrome we will have two middle points
	
	// consider every adjacent pair of digits as mid points and
	// expand in both directions to find maximum length palindrome
	for (int i = 0; i < n - 1; i++)
		expand(str, i, i + 1, max);
	
	return max;
}

int main()
{
	string str = "546374";
	int n = str.length();

	cout << "Longest length of palidromic sum substring is " 
		<< longestPalindrome(str, n);

	return 0;
}
