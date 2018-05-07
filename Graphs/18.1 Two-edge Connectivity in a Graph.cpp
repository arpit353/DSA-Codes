#include <bits/stdc++.h>
using namespace std;

/*

Given a undirected connected graph, check if the graph is 2-edge connected or not.

A connected graph is 2-edge-connected if it remains connected whenever any edges is removed. A bridge or cut arc is an edge of a graph whose deletion increases its number of connected components. i.e. whose removal disconnects the graph. So if any such bridge exists, the graph is not 2-edge-connected.

For example,
Below graph has 6 vertices and 3 bridges (highlighted in red)

A simple approach is to remove each edge from the graph one by one and run DFS or BFS starting from any vertex. If the DFS or BFS covers all nodes in the graph, then the removed edge cannot be a bridge. If not, that edge is bridge. The time complexity of above solution is O(E(V + E)) where V is number of vertices and E is number of edges in the graph.

We can solve this problem efficiently in one pass of DFS. When we do a DFS from vertex v in an undirected graph, there could be edges which are going out of the sub tree i.e back edges. We can say that the graph is 2-edge connected if and only if for every edge u->v in the graph, there is at-least one back-edge that is going out of subtree rooted at v to some ancestor of u. When we say subtree rooted at v, we mean all v’s descendants including the vertex itself.

In other words, when we backtrack from a vertex v, we need to ensure that there is some back-edge from some descendant of v (including v) to some proper ancestor(parent or above) of v.

How should we modify DFS so that we can check if there is a back-edge going out of every sub tree?

We can modify DFS such that DFS(v) returns the smallest arrival time to which there is an back edge from the sub tree rooted at v. For example, let arrival(v) be the arrival time of vertex v in the DFS. Then if there is a back out of the sub tree rooted at v, it’s to something visited before v & therefore with a smaller arrival value. Remember for a back edge u -> v in a graph,

arrival[u] > arrival[v]

Suppose there are four edges going out of sub-tree rooted at v to vertex a, b, c and d and with arrival time A(a), A(b), A(c) and A(d) respectively. We look at their four arrival times & consider the smallest among them and that will be the value returned by DFS(v). i.e. DFS(v) returns min of A(a), A(b), A(c) and A(d). But before returning, we have to check that min (A(a), A(b), A(c), A(d)) is less than the A(v). If min(A(a), A(b), A(c), A(d)) is less than the A(v), then that means that at-least one back-edge is going out of the sub tree rooted at v. If not, we can say that (parent[v], v) is a bridge.

Output: 

2, 1
3, 5
0, 2

 
Please note that the same edges might end up printed twice. We can use a std::map avoid that with key as vertex number and value as std::set. i.e. std::map<int, set<int>>.

 
The time complexity of above solution is O(n + m) where n is number of vertices and e is number of edges in the graph.


*/

// Number of vertices in the graph
#define N 6

// data structure to store graph edges
struct Edge {
	int src, dest;
};

class Graph
{
public:
	// A array of vectors to represent adjacency list
	vector<int> adjList[N];

	// Constructor
	Graph(vector<Edge> edges)
	{
		// add edges to the undirected graph
		for (int i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;
			
			adjList[src].push_back(dest);
			adjList[dest].push_back(src);
		}
	}
};

// Perform DFS on graph starting from vertex v and find 
// all Bridges in the process
int DFS(Graph const &graph, int v, vector<bool> discovered, 
				int arrival[], int parent, int &time)
{
	// set arrival time of vertex v
	arrival[v] = ++time;
 
	// mark vertex as discovered
	discovered[v] = true;
	
	// initialize arr to arrival time of vertex v
	int arr = arrival[v];

	// (v, w) forms a edge
	for (int w : graph.adjList[v])
	{
		// w is not discovered
		if (!discovered[w])
			arr = min(arr, DFS(graph, w, discovered,
							arrival, v, time));

		// w is discovered and w is not parent of v
		else if (w != parent) 
			// If the vertex w is already discovered, that 
			// means that there is a back edge starting 
			// from v. Note that as discovered[u] is already 
			// true, arrival[u] is already defined
			arr = min(arr, arrival[w]);
	}
	
	// if value of arr remains unchanged i.e. it is equal 
	// to the arrival time of vertex v and if v is not root
	// node, then (parent[v] -> v) forms a Bridge
	if (arr == arrival[v] && parent != -1) 
		cout << parent << ", " << v << endl;

	// we return the minimum arrival time
	return arr;
}

// main function
int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = { 
		{0, 2}, {1, 2}, {2, 3}, {2, 4}, {3, 4}, {3, 5} 
	};
	
	// create a graph from above edges
	Graph graph(edges);

	// stores vertex is discovered or not
	vector<bool> discovered(N);
	
	// stores arrival time of a node in DFS
	int arrival[N];

	int start = 0, parent = -1, time = 0;
	
	// As given graph is connected, DFS will cover every node
	DFS(graph, start, discovered, arrival, parent, time);
	
	return 0;
}
