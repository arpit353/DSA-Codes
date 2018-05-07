#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

// Function to find the first k non-repeating character in 
// the string by doing only one traversal of it
int firstKNonRepeating(string str, int k)
{
	// map to store character count and the index of its 
	// last occurrence in the string
	unordered_map<char, pair<int, int>> map;
	int n = str.length();

	for (int i = 0 ; i < n; i++)
	{
		map[str[i]].first++;
		map[str[i]].second = i;
	}
	
	// create an empty max-heap (max size k)
	priority_queue<int, vector<int>> pq;

	// traverse the map and process index of all characters 
	// having count of 1
	for (auto it : map)
	{
		int count = it.second.first;
		int index = it.second.second;

		if (count == 1)
		{
			// if heap has less than k keys in it
			// push index of current character
			if (--k >= 0)
			{
				pq.push(index);
			}
			// else if index of current element is less than the root of the
			// heap, replace the root with the current element
			else if (index < pq.top())
			{
				pq.pop();
				pq.push(index);
			}
		}
	}

	// Now the heap contains index of first k non-repeating characters
	
	// pop all keys from the max-heap
	while (!pq.empty())
	{
		// extract the maximum node from the max-heap
		int max_index = pq.top();
		pq.pop();
 
		cout << str[max_index] << " ";
	}
}

int main()
{
	string str = "ABCDBAGHCHFAC";
	int k = 3;

	firstKNonRepeating(str, k);
	
	return 0;
}