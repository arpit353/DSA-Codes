#include <iostream>
#include <unordered_map>
using namespace std;
 
/*

We have used multimap because there may be more that one time when same sum come. for example in start sum was 3 then after some time sum become 3 and after some more traversal sum become 3. So both subarray from start 3 to second 3 and from second 3 to end 3 all sums to 0. so every subarray should be printed. thats why we store it in multimap with same key. Multimap can have more than one element with same key.


*/


// Function to print all sub-arrays with 0 sum present
// in the given array
void printallSubarrays(int arr[], int n)
{
    // create an empty multi-map to store ending index of all sub-arrays
    // having given sum
	unordered_multimap<int, int> map;

	// insert (0, -1) pair into the set to handle the case when sub-array
	// with 0 sum starts from index 0
	map.insert(pair<int, int>(0, -1));

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
	    // sum of elements so far
		sum += arr[i];

		// if sum is seen before, there exists at-least one sub-array with 0 sum
		if (map.find(sum) != map.end())
		{
			auto it = map.find(sum);

			// find all sub-arrays with same sum
            while (it != map.end() && it->first == sum)
            {
                cout << "Subarray [" << (it->second + 1) << ".." << i << "]\n";
                it++;
            }
		}

		// insert (sum so far, current index) pair into multi-map
		map.insert(pair<int, int>(sum, i));
	}
}

// main function
int main()
{
    int arr[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
	int n = sizeof(arr)/sizeof(arr[0]);

	printallSubarrays(arr, n);

	return 0;
}


/*

We can use multimap to print all sub-arrays with 0 sum present in the given array. The idea is to create an empty multi-map to store ending index of all sub-arrays having given sum. We traverse the given array, and maintain sum of elements seen so far. If sum is seen before, there exists at-least one sub-array with 0 sum which ends at current index and we print all such sub-arrays.

*/
