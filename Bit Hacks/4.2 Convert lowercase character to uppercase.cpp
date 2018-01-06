#include<iostream>

using namespace std;

int main()
{
	// Convert lowercase character to uppercase
	for (char ch = 'a'; ch <= 'z'; ch++)
    	cout << char(ch & '_'); // prints ABCDEFGHIJKLMNOPQRSTUVWXYZ

    return 0;
}
