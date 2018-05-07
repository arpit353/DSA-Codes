#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

bool validateSentence(string str)
{
	int index = 0;
	if (islower(str[index])) // 1st condition
		return false;

	while (str[index]) 
	{
		if (isupper(str[index])) 
		{
			if (isupper(str[index + 1])) // 5th condition
				return false;

			if (index - 1 >= 0 && str[index - 1] != ' ') // 2nd condition
				return false;
		}

		if (str[index] == ' ' && str[index + 1] == ' ') // 4th condition
				return false;

		index++;
	}

	if (str[index - 2] == ' ' || str[index - 1] != '.') // 3th condition
		return false;

	return true;
}

int main()
{
	vector<string> list = 
	{
		"This sentence is syntactically correct.",

		"This sentence is syntactically  incorrect as two "
		"continuous spaces are not allowed.",
		
		"This sentence is syntactically correct Y.",
		
		"This sentence is syntactically incorRect as uppercase "
		"character is not allowed midway of the string.",
		
		"THis sentence is syntactically incorrect as lowercase "
		"character don't follow the first uppercase character.",
		
		"This sentence is syntactically incorrect as it doesn't "
		"end with a full stop"
	};

	cout << "Valid sentences are - \n";
	for (string str: list)
		if (validateSentence(str))
			cout << str << endl;
	
	return 0;
}