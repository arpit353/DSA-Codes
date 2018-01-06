#include<iostream>

using namespace std;

int main()
{
	
	// Convert lowercase alphabet to uppercase
	for (char ch = 'a'; ch <= 'z'; ch++)
    	cout << char(ch ^ ' '); // prints ABCDEFGHIJKLMNOPQRSTUVWXYZ
 
	// Convert uppercase alphabet to lowercase
	for (char ch = 'A'; ch <= 'Z'; ch++)
    	cout << char(ch ^ ' '); // prints abcdefghijklmnopqrstuvwxyz

    return 0;

}
