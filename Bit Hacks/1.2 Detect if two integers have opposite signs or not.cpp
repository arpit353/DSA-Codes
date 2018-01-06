#include <iostream>
#include <bitset>
using namespace std;

/*

00…000100   ^              (x = 4)
00…001000                  (y = 8)
~~~~~~~~~
00…001100                  positive number
 

00…000100   ^              (x = 4)
11…111000                  (y = -8)
~~~~~~~~~
11…111100                  negative number

Simply if the 'OR' between the numbers is negative then both have opposite sign either one of then will be negative.

*/
 
int main()
{
	int x = 4;
 	int y = -8;
 	
 	cout << x << "  in binary is " << bitset<32>(x) << endl;
 	cout << y << " in binary is " << bitset<32>(y) << endl;
 	
 	// true iff x and y have opposite signs
	bool isOpposite = ((x ^ y) < 0);
	
	if (isOpposite)
		cout << x << " and " << y << " have opposite signs";
	else
		cout << x << " and " << y << " don't have opposite signs";	
	
	return 0;
}