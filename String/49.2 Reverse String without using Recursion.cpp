#include <bits/stdc++.h>
using namespace std;

// Iterative function to reverse a given string
// Note string is passed as reference parameter
void reverse(string &str, int n)
{
	// create an empty stack of characters
	stack<char> stk;

	// push every character of the given string into the stack
	for (int i = 0; i < n; i++)
		stk.push(str[i]);
	
	// start from index 0
	int k = 0;
	
	// pop characters from the stack until it is empty
	while (!stk.empty())
	{ 
		// assign each popped character back to the input string
		str[k++] = stk.top();
		stk.pop();
	}
}

// main function
int main()
{
	string str = "Techie Delight";
	
	reverse(str, str.length());
	cout << "Reverse of given string is : " << str;

	return 0;
}