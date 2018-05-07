#include <bits/stdc++.h>
using namespace std;

/*
bool isNumber(const string& str)
{
	for (char ch: str)
		if (!isdigit(ch)) 
			return false; 
			
	return true;
}

bool isNumber(const string& str)
{
	return !str.empty() && find_if(str.begin(), str.end(), 
		[](char c) { return !isdigit(c); }) == str.end();
}
*/

// check if given string is a numeric string or not
bool isNumber(const string& str)
{
	// std::find_first_not_of searches the string for the 
	// first character that does not match any of the 
	// characters specified in its arguments
	return !str.empty() && 
		(str.find_first_not_of("[0123456789]") == std::string::npos);
}

// Function to split string str using given delimiter
vector<string> split(const string& str, char delim)
{
	auto i = 0;
	vector<string> list;

	auto pos = str.find(delim);
	
	while (pos != string::npos) 
	{
		list.push_back(str.substr(i, pos - i));
		i = ++pos;
		pos = str.find(delim, pos);
	}
	
	list.push_back(str.substr(i, str.length()));
	
	return list;
}

// Function to validate an IP address
bool validateIP(string ip)
{
	// split the string into tokens
	vector<string> list = split(ip, '.');

	// if token size is not equal to four
	if (list.size() != 4)
		return false;

	// validate each token
	for (string str : list) 
	{
		// verify that string is number or not and the numbers 
		// are in the valid range
		if (!isNumber(str) || stoi(str) > 255 || stoi(str) < 0)
			return false;
	}

	return true;
}

int main()
{
	string ip = "14.8.9.28";
	// string ip = "100.xyz.1.15";
	// string ip = "115.300.10.60";

	if (validateIP(ip))
		cout << "Valid IP Address";
	else
		cout << "Invalid IP Address";

	return 0;
}