#include <bits/stdc++.h>
using namespace std;

// Function to print given string in zig-zag form in k rows
void printZigZag(string str, int k)
{
	// base case
	if (k == 1) 
	{
		cout << str;
		return;
	}
	
	// print first row
	for (int i = 0; i < str.length(); i += (k-1)*2)
		cout << str[i];

	// print middle rows
	for (int j = 1; j < k - 1; j++) 
	{
		bool down = true;
		for (int i = j; i < str.length();) 
		{
			cout << str[i];
			if (down) // going down
				i += (k-j-1)*2;
			else // going up
				i += (k-1)*2 - (k-j-1)*2;

			down = !down; // switch direction
		}
	}
	
	// print last row
	for (int i = k - 1; i < str.length(); i += (k-1)*2)
		cout << str[i];
}

int main()
{
	string str = "THISPROBLEMISAWESOME";
	int k = 4;
	
	printZigZag(str, k);
	
	return 0;
}
