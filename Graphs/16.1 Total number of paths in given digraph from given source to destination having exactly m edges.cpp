#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*

Given a digraph (Directed Graph), find the total number of routes to reach the destination from given source that have exactly m edges.

For example, consider below graph,
 
find-number-of-routes-in-diagraph

Let source = 0, destination = 3, no. of edges m = 4

It has 3 routes from source 0 to destination 3

0-1-5-2-3
0-1-6-5-3
0-6-5-2-3

The solution should return number of routes 3.

The idea is to do BFS traversal from the given source vertex. BFS is generally used to find shortest paths in graphs/matrix but we can modify normal BFS to meet our requirements. Usually BFS don’t explore already discovered vertex again, but here we do the opposite. In order to cover all possible paths from source to destination, we remove this check from BFS. But if the graph contains a cycle, removing this check will cause program to go into an infinite loop. We can easily handle that if we don’t consider nodes having BFS depth of more than m. Basically we maintain two things in BFS queue node –

current vertex number
current depth of BFS (i.e. how far away current node is from the source?)

So whenever destination vertex is reached and BFS depth is equal to m, we update the result. The BFS will terminate when we have explored every path in the given graph or BFS depth exceeds m.

*/

// data structure to store graph edges
struct Edge {
    int src, dest;
};

// class to represent a graph object
class Graph
{
public:
    // An array of vectors to represent adjacency list
    vector<int> *adjList;

    // Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // allocate memory
        adjList = new vector<int>[N];

        // add edges to the directed graph
        for (int i = 0; i < edges.size(); i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            adjList[src].push_back(dest);
        }
    }
};

// BFS Node
struct Node
{
    // stores current vertex number and current depth of
    // BFS (how far away current node is from the source?)
    int vertex, depth;
};

// Perform BFS on graph g starting from vertex v
int modifiedBFS(Graph const &g, int src, int dest, int m)
{
    // create a queue used to do BFS
    queue<Node> q;

    // push source vertex into the queue
    q.push({src, 0});

    // stores number of paths from source to destination
    // having exactly m edges
    int count = 0;

    // run till queue is not empty
    while (!q.empty())
    {
        // pop front node from queue
        Node node = q.front();
        q.pop();

        int v = node.vertex;
        int depth = node.depth;

        // if destination is reached and BFS depth is equal to m
        // update count
        if (v == dest && depth == m)
            count++;

        // don't consider nodes having BFS depth more than m.
        // This check will result in optimized code and also
        // handle cycles in the graph (else loop will never break)
        if (depth > m)
            break;

        // do for every adjacent vertex u of v
        for (int u : g.adjList[v])
        {
            // push every vertex (discovered or undiscovered) into the queue
            q.push({u, depth + 1});
        }
    }

    // return number of paths from source to destination
    return count;
}

// main function
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges =
    {
        {0, 6}, {0, 1}, {1, 6}, {1, 5}, {1, 2}, {2, 3}, {3, 4},
        {5, 2}, {5, 3}, {5, 4}, {6, 5}, {7, 6}, {7, 1}
    };

    // Number of nodes in the graph
    int N = 8;

    // create a graph from edges
    Graph g(edges, N);

    int src = 0, dest = 3, m = 4;

    // Do modified BFS traversal from source vertex src
    cout << modifiedBFS(g, src, dest, m);

    return 0;
}
