#include <iostream>
using namespace std;

/*

00010100   &                 (n = 20)
00000001                     (1)
~~~~~~~~
00000000

This can be used to find if the  umber was odd or even.

*/


int main() 
{
	int n = 5;
	
	if (n & 1)
		cout << n << " is odd";
	else
		cout << n << " is even";

	return 0;
}