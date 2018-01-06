#include <bits/stdc++.h>
using namespace std;

/*

Given a list containing future prediction of share prices, find maximum profit that can be earned by buying and selling shares any number of times with constraint that a new transaction can only start after previous transaction is complete. i.e. we can only hold at-most one share at a time.

For example,

rate[]:  {1, 5, 2, 3, 7, 6, 4, 5}
Total profit earned is 10

Buy on day 1 and sell on day 2
Buy on day 3 and sell on day 5
Buy on day 7 and sell on day 8

rate[]: {10, 8, 6, 5, 4, 2}

Total profit earned is 0
 
The idea is very simple. We traverse the given list of prices and find local minimum of every increasing sequence. For example, in the array {1, 5, 2, 3, 7, 6, 4, 5}, below are three increasing sequences of length 2 or more.

{1, 5}
{2, 3, 7}
{4, 5}

The local minimum of each sequence is 1, 2 and 4 respectively. We can gain maximum profit if we buy the shares at the starting of every increasing sequence (local minimum) and sell them at the end of the increasing sequence (local maximum).

*/


// Function to find maximum profit that can be earned by buying and 
// selling shares any number of times
int maxProfit(int rate[], int n)
{
    // store maximum profit gained
    int profit = 0;

    // initialize local minimum to first element's index
	int j = 0;

	// start from second element
	for (int i = 1; i < n; i++)
	{
        // update local minimum if decreasing sequence is found
		if (rate[i - 1] > rate[i])
			j = i;

        // sell shares if current element is peak (previous < current > next)
		if (rate[i - 1] < rate[i] &&
                (i + 1 == n || rate[i] > rate[i + 1]))
        {
            profit += (rate[i] - rate[j]);
            printf("Buy on day %d and sell on day %d\n", j + 1, i + 1);
        }
	}

	return profit;
}

// main function
int main()
{
	int rate[] = { 1, 5, 2, 3, 7, 6, 4, 5 };
	int n = sizeof(rate) / sizeof(rate[0]);

	cout << "\nTotal profit earned is " << maxProfit(rate, n);

	return 0;
}
