#include <iostream>
using namespace std;

// Function to check if X can be derived from Y by rotating it
bool check(string X, string Y)
{
	return (X.length() == Y.length()) && ((X + X).find(Y) != string::npos);
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
