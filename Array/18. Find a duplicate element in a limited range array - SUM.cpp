#include <numeric>
#include <iostream>
#include <array>

/*

Take the sum subtract it we will getthe answer

*/

template <typename It>
int find_duplicate(It start, It finish)
{
    auto size = std::distance(start, finish);

    int actual_sum = std::accumulate(start, finish, 0);
    int expected_sum = size * (size - 1) / 2;

    return actual_sum - expected_sum;
}

int main()
{
    std::array<int, 5> arr1 = {{ 1, 2, 3, 4, 4 }};
    std::array<int, 5> arr2 = {{ 1, 2, 3, 4, 2 }};

    std::cout << "The duplicate element is " << 
    			find_duplicate(arr1.begin(), arr1.end()) << '\n';

    std::cout << "The duplicate element is " << 
    			find_duplicate(arr2.begin(), arr2.end()) << '\n';
}