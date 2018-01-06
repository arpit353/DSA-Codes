#include <iostream>
#include <bitset>
using namespace std;

/*

The expression -~x will add 1 to a given integer. We know that to get negative of a number, we invert its bits and add 1 to it (Remember negative numbers are stores in 2’s compliment form). i.e.

-x = ~x + 1;
-~x = x + 1 (by replacing x by ~x)

*/
 
int main()
{
	int x = 4;
 	cout << x << " + " << 1 << " is " << -~x << endl;	
	
	x = -5;
 	cout << x << " + " << 1 << " is " << -~x << endl;	
	
	x = 0;
 	cout << x << " + " << 1 << " is " << -~x << endl;
	
	return 0;
}