#include <iostream>
using namespace std;

// Perform Run Length Encoding (RLE) data compression algorithm 
// on string str
string encode(string str)
{
	// stores output string
	string encoding = "";
	int count;

	for (int i = 0; str[i]; i++) 
	{
		// count occurrences of character at index i
		count = 1;
		while (str[i] == str[i + 1])
			count++, i++;

		// append current character and its count to the result
		encoding += to_string(count) + str[i];
	}

	return encoding;
}

int main()
{
	string str = "ABBCCCD";
	
	cout << encode(str);
	
	return 0;
}