#include <bits/stdc++.h>
using namespace std;

// Recursive function to reverse a given string
// Note string is passed as reference parameter
void reverse(string &str, int l, int h)
{
	if (l < h)
	{
		swap(str[l], str[h]);
		reverse(str, l + 1, h - 1);
	}
}

// main function
int main()
{
	string str = "Techie Delight";
 
	reverse(str, 0, str.length() - 1);
	cout << "Reverse of the given string is : " << str;
 
	return 0;
}