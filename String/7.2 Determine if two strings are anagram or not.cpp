#include <iostream>
#include <unordered_map>
using namespace std;

// Function to check if X and Y are anagrams or not
bool isAnagram(string X, string Y)
{
	// if X's length is not same as Y's, they can't be anagram
	if (X.length() != Y.length())
		return false;
	
	// create an empty map
    unordered_map<int, int> freqX;

	// maintain count of each character of X in the map
    for (char x: X)
        freqX[x]++;

	// create an second map
    unordered_map<int, int> freqY;

	// maintain count of each character of Y in the map
    for (char y: Y)
        freqY[y]++;

	// return true if both map has same content
    return freqX == freqY;
}
 
int main()
{
    string X = "tommarvoloriddle";	// Tom Marvolo Riddle
    string Y = "iamlordvoldemort";	// I am Lord Voldemort

    if (isAnagram(X, Y))
    	cout << "Anagram";
    else
    	cout << "Not a Anagram";
 
    return 0;
}