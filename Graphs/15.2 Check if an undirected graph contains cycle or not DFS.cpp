#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*

When we do a DFS from any vertex v in an undirected graph, we may encounter back-edge that points to one of the ancestors of current vertex v in the DFS tree. Each “back edge” defines a cycle in an undirected graph. If the back edge is x -> y then since y is ancestor of node x, we have a path from y to x. So we can say that we have a path y ~~ x ~ y that forms a cycle. (Here ~~ represents one more more edges in the path and ~ represents a direct edge).

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

        // add edges to the undirected graph
        for (unsigned i = 0; i < edges.size(); i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }
};

// Perform DFS on graph and returns true if any back-edge
// is found in the graph
bool DFS(Graph const &graph, int v, vector<bool> &discovered,
		int parent)
{
    // mark current node as discovered
    discovered[v] = true;

    // do for every edge (v -> w)
    for (int w : graph.adjList[v])
    {
        // w is not discovered
        if (!discovered[w])
        {
            if (DFS(graph, w, discovered, v))
                return true;
        }

        // w is discovered and w is not a parent
        else if (w != parent)
        {
            // we found a back-edge (cycle)
            return true;
        }
    }

    // No back-edges found in the graph
    return false;
}

// Check if an undirected graph contains cycle or not
int main()
{
    // initialize edges as per above diagram
    vector<Edge> edges =
    {
        {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
        {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}, {11, 12}
        // edge (11->12) introduces a cycle in the graph
    };

    // Number of nodes in the graph
    int N = 13;

	// create a graph from given edges
	Graph graph(edges, N);

    // stores vertex is discovered or not
    vector<bool> discovered(N);

    // Do DFS traversal from first vertex
    if (DFS(graph, 1, discovered, -1))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain any cycle";

    return 0;
}
