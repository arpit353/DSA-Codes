#include <stdio.h>
#include <limits.h>

/*

We know that divisions can be solved by repeatedly subtracting the divisor from the dividend till the dividend becomes less than the divisor. The number of times the repeated subtraction is carried out is equal to the quotient.

*/

// Function to perform division (x / y) of two numbers x and y without 
// using division operator in the code
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

	// initialize quotient by 0
	int quotient = 0;

	// loop till dividend x is more than the divisor y
	while (x >= y)
	{
	   x = x - y;		// perform reduction on dividend
	   quotient++;		// increase quotient by 1
	}

	printf("Remainder is %d\n", x);

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