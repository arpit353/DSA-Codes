#include <bits/stdc++.h>
using namespace std;

typedef vector<double> Trains;

/*

Given a schedule containing arrival and departure time of trains in a station, find minimum number of platforms needed in the station so to avoid any delay in arrival of any train.

For example,

Trains arrival   = { 2.00, 2.10, 3.00, 3.20, 3.50, 5.00 };
Trains departure = { 2.30, 3.40, 3.20, 4.30, 4.00, 5.20 };

Minimum platforms needed is 2

*/


/*

We maintain a counter to count number of trains present at the station at any point of time. The counter also represents number of platforms needed at that time.

If train is scheduled to arrive next, we increase the counter by 1 and update minimum platforms needed if count is more than minimum platforms needed so far.
 
If train is scheduled to depart next, we decrease the counter by 1.
One special case we need to handle. When two trains are scheduled to arrive and depart at the same time, we depart the train first

*/


// Function to find minimum number of platforms needed in the 
// station so to avoid any delay in arrival of any train.
int minPlatforms(Trains arrival, Trains departure)
{
    // maintains the count of trains
    int count = 0;

    // stores minimum platforms needed
    int platforms = 0;

    // take two indexes for arrival and departure time
    int i = 0, j = 0;

    // run till train is scheduled to arrive
    while (i < arrival.size())
    {
        // if train is scheduled to arrive next
        if (arrival[i] < departure[j])
        {
            // increase the count of trains and update minimum platforms if required
            platforms = max(platforms, ++count);

            // move the pointer to next arrival
            i++;
        }

        // if train is scheduled to depart next i.e. (departure[j] < arrival[i]),
        // decrease the count of trains & move pointer j to next departure

        // If two trains are arriving and departing at the same time, i.e.
        // (arrival[i] == departure[j]) depart the train first
        else
            count--, j++;
    }

    return platforms;
}

// main function
int main()
{
    Trains arrival =   { 2.00, 2.10, 3.00, 3.20, 3.50, 5.00 };
    Trains departure = { 2.30, 3.40, 3.20, 4.30, 4.00, 5.20 };

    // sort arrival time of trains
    sort(arrival.begin(), arrival.end());

    // sort departure time of trains
    sort(departure.begin(), departure.end());

    cout << "Minimum platforms needed is " << minPlatforms(arrival, departure);

    return 0;
}
