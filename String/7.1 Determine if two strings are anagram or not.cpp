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
    unordered_map<int, int> freq;

	// maintain count of each character of X in the map
    for (char x: X)
        freq[x]++;
 
	// do for each character of Y
    for (char y: Y)
    {
    	// if y is not found in map i.e. either y is not present
    	// in string X or has more occurences in string Y
    	if (freq.find(y) == freq.end())
    		return false;

    	// decrease the frequency of y in the map
    	freq[y]--;

    	// if its frequency become 0, erase it from map
    	if (!freq[y])
    		freq.erase(y);
    }

	// return true if map becomes empty
    return !freq.size();
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