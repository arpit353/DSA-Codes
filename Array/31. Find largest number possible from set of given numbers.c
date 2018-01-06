#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*

Simply sorting the array in descending order and considering the sorted order is not a possibility here as sorted array {75, 68, 21, 12, 10, 7} will result in number 75682112107 which is less than largest number possible 77568211210.

The idea is to write our own custom comparator function for the sorting routine. For two numbers X and Y, the custom comparator function will not compare X and Y with each other but it compares XY with YX and the greater number will come first in sorted order. Here, XY denotes number formed by appending Y to X and YX denotes number formed by appending X to Y.

For example, for X = 15 and Y = 4, XY = 154 and YX = 415.
As evident from above example, X > Y but XY < YX, so the comparator function will consider Y > X.

*/


/*
Note - An element of arr is of type char*, and the const void* in
compare point to *char, so what is actually being passed is a char**.
Therefore, proper cast is *(const char**)a
*/
int compare(const void *a, const void *b)
{
	const char **X = (const char **)a;
	const char **Y = (const char **)b;

	int len = strlen(*X) + strlen(*Y) + 1;

	// create a new string X + Y
	char XY[len];
	strcpy(XY, *X);
	strcat(XY, *Y);

	// create a new string Y + X
	char YX[len];
	strcpy(YX, *Y);
	strcat(YX, *X);

	// larger of YX and XY should come first in sorted array
	return strcmp(YX, XY);
}

// main function
int main()
{
	char *arr[] = { "10", "68", "97", "9", "21", "12" };
	int n = sizeof(arr)/sizeof(arr[0]);

    // custom sort
	qsort(arr, n, sizeof(arr[0]), compare);

	// print the sorted sequence
	for (int i = 0; i < n ; i++ )
		printf("%s", arr[i]);

	return 0;
}
