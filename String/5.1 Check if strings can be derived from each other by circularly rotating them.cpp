#include <iostream>
#include <algorithm>
using namespace std;

// Function to check if X can be derived from Y by rotating it
bool check(string X, string Y)
{
	int m;
	
	// if string lengths are different, they can't be 
	// derived from each other
	if ((m = X.length()) != Y.length())
		return false;

	// Invariant : At i'th iteration of this loop, 
	// string X will be rotated by i units
	for (int i = 0; i < m; i++)
	{
		// left rotate string X by 1 unit
		rotate(X.begin(), X.begin() + 1, X.end());

		// for right rotation, we can use reverse iterators. 
		// i.e. rotate(X.rbegin(), X.rbegin() + 1, X.rend());
	
		// return true if X becomes equal to Y
		if (!X.compare(Y))
			return true;
	}
	
	// return false if no rotation is matched
	return false;
}

int main() 
{
	string X = "ABCD";
	string Y = "DABC";
	
	if (check(X, Y))
		cout << "Given strings can be derived from each other";
	else 
		cout << "Given strings cannot be derived from each other";

	return 0;
}
