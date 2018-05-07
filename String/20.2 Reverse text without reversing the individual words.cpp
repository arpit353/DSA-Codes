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

	// scan the text
	for (int i = 0; i < n; i++)
	{
		// if space is found, we found a word
		if (str[i] == ' ')
		{
			// reverse the found word
			reverse(str, low, high);
			
			// reset low and high for next word
			low = high = i + 1;
		}
		else high = i;
	}
	
	// reverse last word
	reverse(str, low, high);
	
	// reverse the whole text
	reverse(str, 0, n - 1);

	// we can also use STL reverse function
	/*
		reverse(str.begin() + low, str.begin() + high + 1);	
		reverse(str.begin(), str.end()); 
	*/
}

int main() 
{
	string str = "preparation Interview Technical IT for material good provide We";
	
	reverse(str);
	cout << "" << str; 
	
	return 0;
}