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

	for (int i = 0 ; i < str.length(); i++)
	{
		map[str[i]].first++;
		map[str[i]].second = i;
	}
	
	// create an empty min-heap
	priority_queue<int, vector<int>, greater<int>> pq;
	
	// traverse the map and push index of all characters 
	// having count of 1 into the min-heap 
	for (auto it : map)
	{
		int count = it.second.first;
		int index = it.second.second;

		if (count == 1)
			pq.push(index);
	}

	// pop top k keys from the min-heap
	while (k-- && !pq.empty())
	{
		// extract the minimum node from the min-heap
		int min_index = pq.top();
		pq.pop();
 		
		cout << str[min_index] << " ";
	}
}

int main()
{
	string str = "ABCDBAGHCHFAC";
	int k = 3;

	firstKNonRepeating(str, k);
	
	return 0;
}