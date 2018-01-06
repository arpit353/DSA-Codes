#include<iostream>

using namespace std;

/*
The trick lies in ASCII codes of ‘A’-‘Z’ and ‘a’-‘z’ –

‘A’ – 01000001 ‘a’ – 01100001
‘B’ – 01000010 ‘b’ – 01100010
‘C’ – 01000011 ‘c’ – 01100011
‘D’ – 01000100 ‘d’ – 01100100
‘E’ – 01000101 ‘e’ – 01100101
and so on…

If we carefully analyze, we will notice that ASCII codes of lowercase and uppercase characters differ only in their third significant bit. For uppercase characters, the bit is 0 and for lowercase characters the bit is 1. If we could find a way to set/unset that particular bit, we can easily invert case of any character. Now space ‘ ‘ has ASCII code of 00100000 and ‘_’ has ASCII code of 01011111.

If we take OR of an uppercase characters with ‘ ‘, the third significant bit will be set and we will get its lowercase equivalent.
 
If we take AND of a lowercase character with ‘_’, the third significant bit will be unset and we will get its uppercase equivalent.
 
If we take XOR of an uppercase or lowercase characters with ‘ ‘ (ASCII 00100000), only its third significant bit will be toggled. i.e. lowercase becomes uppercase and vice versa.

*/


int main()
{
	// Convert uppercase character to lowercase
	for (char ch = 'A'; ch <= 'Z'; ch++)
    	cout << char(ch | ' '); // prints abcdefghijklmnopqrstuvwxyz

    return 0;
}