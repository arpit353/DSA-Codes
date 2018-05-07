#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

// Function to reverse a given C++ string using std::reverse
// Note string is passed as reference parameter 
void reverse(string& str) 
{
	reverse(str.begin(), str.end());
}

// Function to reverse a given character array using std::reverse
char *reverse(char *str)
{
	std::reverse(str, str + strlen(str));
	return str;
}

// main function
int main() 
{
	/* using C++ string */
	string str = "Techie Delight";
	
	reverse(str);
	cout << "Reverse of the given string is : " << str << endl; 


	/* using C string */
	/*
	char s[] = "Techie Delight";
	
	reverse(s);
	cout << "Reverse of the given string is : " << s; 
	*/

	return 0;
}