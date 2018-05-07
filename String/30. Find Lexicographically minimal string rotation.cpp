#include <iostream>
#include <algorithm>
using namespace std;

// Function to find Lexicographically minimal string rotation
string findLexicalMinRotation(string str)
{
	// To store lexicographic minimum string
	string min = str;

	for (int i = 0; i < str.length(); i++)
	{
		// left rotate string by 1 unit
	    rotate(str.begin(), str.begin() + 1, str.end());

	    // check if the rotation is minimum so far
	    if (str.compare(min) < 0)
	        min = str;
	}

	return min;
}

// main function
int main()
{
	string str = "bbaaccaadd";

	cout << "The lexicographically minimal rotation of " << str 
			<< " is " << findLexicalMinRotation(str);

	return 0;
}