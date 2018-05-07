#include <bits/stdc++.h>
using namespace std;

// Reverse substring str[begin..end]
void reverse(string &str, int begin, int end)
{
	while (begin < end)
		swap(str[begin++], str[end--]);
}

// Function to reverse a text without reversing the individual words
// Note that string is passed by reference
void reverse(string &str)
{
	int n = str.length();
	
	// str[low..high] forms a word
	int low = 0, high = 0;
	
	// create an empty stack
	stack<string> stk;
	
	// scan the text
	for (int i = 0; i < n; i++)
	{
		// if space is found, we found a word
		if (str[i] == ' ')
		{
			// push each word into the stack
			stk.push(str.substr(low, high - low + 1));
			
			// reset low and high for next word
			low = high = i + 1;
		}
		else high = i;
	}
	
	str.erase(str.begin(), str.end());		// empty the string
	
	// fill the string by following LIFO order
	while (!stk.empty())
	{
		str += stk.top() + " ";
		stk.pop();
	}
	
	str.erase(str.end() - 1, str.end());	// remove last space
	
}

int main() 
{
	string str = "preparation Interview Technical IT for material good provide We";
	
	reverse(str);
	cout << "" << str; 
	
	return 0;
}