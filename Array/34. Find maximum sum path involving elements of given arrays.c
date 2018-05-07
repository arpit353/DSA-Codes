#include <stdio.h>

// Utility function to find minimum of two integers
int max (int x, int y)
{
    return (x > y) ? x : y;
}


// This code handles the case of both array. This is noyt just about choosing one array. What happens is we take iterators to both the arrays then we move them until they reach common elements. obousily if one array reached to common element then other array will elements will be lesser then the element of other array. This will cause summing of other array.

// Function to find maximum sum path in two given arrays
// Below code is similar to merge routine of mergesort algorithm
int maxSum(int X[], int Y[], int m, int n)
{
    int sum = 0;
    int sum_x = 0, sum_y = 0;

    // i and j denotes current index of X and Y respectively
    int i = 0, j = 0;

    // loop till X and Y are not empty
    while (i < m && j < n)
    {
        // to handle duplicate elements in X
        while (i < m-1 && X[i] == X[i+1])
            sum_x += X[i++];

        // to handle duplicate elements in Y
        while (j < n-1 && Y[j] == Y[j+1])
            sum_y += Y[j++];

        // if current element of Y is less than current element of X
        if (Y[j] < X[i])
        {
            sum_y += Y[j];
            j++;
        }

        // if current element of X is less than current element of Y
        else if (X[i] < Y[j])
        {
            sum_x += X[i];
            i++;
        }

        else // if (X[i] == Y[j])
        {
            // consider maximum sum and include value of current cell
            sum += max(sum_x, sum_y) + X[i];

            // move both indices by 1 position
            i++, j++;

            // reset both sums
            sum_x = 0, sum_y = 0;
        }
    }

    // process remaining elements of X (if any)
    while (i < m)
        sum += X[i++];

    // process remaining elements of Y (if any)
    while (j < n)
        sum += Y[j++];

    return sum;
}

// main function
int main()
{
    int X[] = { 3, 6, 7, 8, 10, 12, 15, 18, 100 };
    int Y[] = { 1, 2, 3, 5, 7, 9, 10, 11, 15, 16, 18, 25, 50 };

    int m = sizeof(X)/sizeof(X[0]);
    int n = sizeof(Y)/sizeof(Y[0]);

    printf("Maximum sum is %d", maxSum(X, Y, m, n));

    return 0;
}