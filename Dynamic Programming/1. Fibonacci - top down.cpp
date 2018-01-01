#include <iostream>
#include <unordered_map>
using namespace std;

int fib(int n, auto &lookup)
{
    if (n <= 1)
        return n;

    if (lookup.find(n) == lookup.end())
        lookup[n] = fib(n - 1, lookup) + fib(n - 2, lookup);

    return lookup[n];

}

int main()
{

    int n;

    cout<<"Enter n \n";
    cin>>n;

    unordered_map<int, int> lookup;
    cout << fib(n, lookup);
    return 0;

}
