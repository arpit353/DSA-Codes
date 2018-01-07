#include <stdio.h>
#include <stdlib.h>

/*

Similar as previous but in this we are in a hurray. We double each time the quotient.to reduce the number of steps. That's why after crossing the dividend we reduce the quotient as it may have crossed theactual quotient. We subtract the y from the quotient.

*/

// Function to perform division (x / y) of two numbers x and y 
// without using division operator in the code
int divide(int x, int y)
{
	// handle divisibility by 0
	if (y == 0)
	{
		printf("Error!! Divisible by 0");
		exit(1);
	}

	// store sign of the result
	int sign = 1;
	if (x * y < 0)
		sign = -1;

	// convert both dividend and divisor to positive
	x = abs(x), y = abs(y);

	// initialize denominator by y
	int denominator = y;

	// initialize quotient by 1
	int quotient = 1;

	// Double denominator and quotient value until denominator is more than 
	// the dividend x
	while (x > denominator)
	{
		denominator *= 2;
		quotient *= 2;
		//printf("%d %d\n", denominator, quotient);
	}

	// Subtract divisor y from denominator and reduce quotient by 1 until 
	// denominator is less than the dividend x
	while (denominator > x)
	{
		denominator -= y;
		quotient -= 1;
		//printf("%d %d\n", denominator, quotient);
	}

	printf("Remainder is %d\n", x - denominator);
	return sign * quotient;
}

// main function to perform division of two numbers
int main(void)
{
	int dividend = 22;
	int divisor = -7;

	printf("Quotient is %d\n", divide(dividend, divisor));

	return 0;
}
