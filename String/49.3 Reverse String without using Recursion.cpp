#include <bits/stdc++.h>
using namespace std;

// Iterative function to reverse a given string
// Note string is passed as reference parameter
void reverse(string &str)
{
	// start with two end points of the given string
	int begin = 0;
	int end = str.length() - 1;
	
	// do till two end-points intersect
	while (begin < end)
		swap(str[begin++], str[end--]);
}

// main function
int main()
{
	string str = "Techie Delight";
	
	reverse(str);
	cout << "" << str; 
	
	return 0;
}