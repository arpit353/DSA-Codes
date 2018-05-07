#include <bits/stdc++.h>
using namespace std;

// Function to convert given number into an excel column
string getColumnName(int n)
{
    // initalize output string as empty
	string res = "";

	while (n > 0)
    {
        // find index of next letter and concatenate the letter
        // to the solution
        // Here index 0 corresponds to 'A' and 25 corresponds to 'Z'
		int index = (n - 1) % 26;
		res = char(index + 'A') + res;
		n = (n - 1) / 26;
	}

	return res;
}

int main()
{
	srand(time(NULL));

	// generate column name for 10 random numbers between 1-1000
	for (int i = 1; i <= 10; i++)
	{
		int r = rand() % 1000 + 1;
		cout << r << " - " << getColumnName(r) << endl;
	}

	return 0;
}
