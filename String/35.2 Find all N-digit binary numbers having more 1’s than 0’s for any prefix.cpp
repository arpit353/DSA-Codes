#include <iostream>
#include <string>

// Function to find all N-digit binary numbers having
// more 1's than 0's at any position
void Solution(std::string currentNumber, int extraOnes, int remainingPlaces)
{
	// If the number is completed, print it
	if (0 == remainingPlaces)
	{
		std::cout << currentNumber << std::endl;
		return;
	}
	
	// Append 1 to the current number and reduce the remaining places by one
	Solution(currentNumber + "1", extraOnes + 1, remainingPlaces - 1);
	
	// If there are more ones than zeroes, append 0 to the current number 
	// and reduce the remaining places by one
	if (0 < extraOnes)
	{
		Solution(currentNumber + "0", extraOnes - 1, remainingPlaces - 1);
	}
}

// main function
int main()
{
	const int numberOfDigits = 4;
	std::string str;
	
	Solution(str, 0, numberOfDigits);

	return 0;
}