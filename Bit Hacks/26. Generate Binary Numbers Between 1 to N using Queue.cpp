#include <iostream>
#include <queue>
using namespace std;

/*

Given a positive number N, efficiently generate binary numbers between 1 to N using queue data structure and in linear time.

For example, for N = 10, the binary numbers are
1 10 11 100 101 110 111 1000 1001 1010 1011 1100 1101 1110 1111 10000

*/

// Function to generate binary numbers between 1 to N using
// queue data structure
void generate(int n)
{
    // create an empty Queue and push 1 to it
    queue<string> q;
    q.push("1");

    // run n times
    int i = 1;
    while (i++ <= n)
    {
        // append 0 and 1 to the front element of the queue and
        // enqueue both strings
        q.push(q.front() + "0");
        q.push(q.front() + "1");

        // print the front element and dequeue from the queue
        cout << q.front() << ' ';
        q.pop();
    }
}

// main function
int main()
{
    int n = 16;
    generate(n);

    return 0;
}
