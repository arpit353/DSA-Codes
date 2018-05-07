#include <iostream>
#include <vector>
using namespace std;

/*

Given an undirected graph, check if is is a tree or not. In other words, check if given undirected graph is a Acyclic Connected Graph or not.

For example, the graph shown on the right is a tree and the graph on the left is not a tree as it contains a cycle 0-1-2-3-4-5-0.

A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any acyclic connected graph is a tree. We can easily determine acyclic connected graph by doing DFS traversal on the graph. When we do a DFS from any vertex v in an undirected graph, we may encounter back-edge that points to one of the ancestors of current vertex v in the DFS tree. Each “back edge” defines a cycle in an undirected graph. If the back edge is x -> y, then since y is ancestor of node x, we have a path from y to x. So we can say that we have a path y ~~ x ~ y that forms a cycle. (Here ~~ represents one more more edges in the path and ~ represents a direct edge) and is not a tree.

Output: 

Graph is not a Tree

Time complexity of above solution is O(n + m) where n is number of vertices and e is number of edges in the graph.

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
            if (!DFS(graph, w, discovered, v))
                return false;
        }

        // w is discovered and w is not a parent
        else if (w != parent)
        {
            // we found a back-edge (cycle)
            return false;
        }
    }

    // No back-edges found in the graph
    return true;
}

// Determine if an undirected graph is a Tree (Acyclic Connected Graph)
int main()
{
    // initialize edges as per above diagram
    vector<Edge> edges =
    {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}
        // edge (5->0) introduces a cycle in the graph
    };

    // Number of nodes in the graph
    int N = 6;

    // create a graph from edges
    Graph graph(edges, N);

    // stores vertex is discovered or not
    vector<bool> discovered(N);

    // boolean flag to store if the graph is tree or not
    bool isTree = true;

    // Do DFS traversal from first vertex
    isTree = DFS(graph, 0, discovered, -1);

    for (int i = 0; isTree && i < N; i++)
    {
        // any undiscovered vertex means graph is not connected
        if (!discovered[i])
            isTree = false;
    }

    if (isTree)
        cout << "Graph is a Tree";
    else
        cout << "Graph is not a Tree";

    return 0;
}
