#include <iostream>
#include <unordered_map>
using namespace std;

int fib(int n)
{
    if (n <= 1)
        return n;

    int previousFib = 0, currentFib = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int newFib = previousFib + currentFib;
        previousFib = currentFib;
        currentFib  = newFib;
    }

    return currentFib;
}

int main()
{
    cout << fib(8);
    return 0;
}
