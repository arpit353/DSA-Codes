#include <iostream>
using namespace std;

// Function to remove all occurrences of "AB" and "C" 
// from the string
void remove(char* str)
{
	// i maintains position of current char in the input string
	// k maintains the next free position in output string
	int i = 0, k = 0;
	
	// do till we reach the end of the string
	while(str[i])
	{
		// if current char is 'B' and previous char (need not 
		// be adjacent) was 'A', increment i and decrement k
		if (str[i] == 'B' && (k > 0 && str[k - 1] == 'A'))
			--k, ++i;
			
		// if current char is 'C', increment i
		else if (str[i] == 'C')
			++i;
		
		else
		// for any other character, increment both i and k
			str[k++] = str[i++];
	}

	// null-terminate the string
	str[k] = '\0';
}

int main()
{
	char str[] = "ABCACBCAABB";
	
	remove(str);
	cout << "String after removal of \"AB\" and \"C\" is \"" << str << "\"";

	return 0;
}
