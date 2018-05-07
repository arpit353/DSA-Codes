#include <iostream>
#include <vector>
using namespace std;

/*

It is possible to test whether a graph is bipartite or not using Depth-first search algorithm. There are two ways to check for Bipartite graphs –

1. A graph is bipartite if and only if it is 2-colorable.
2. A graph is bipartite if and only if it does not contain an odd cycle.

In previous post, we have checked if the graph contains an odd cycle or not using BFS. Now using DFS, we will check if the graph is 2-colorable or not.

The main idea is to assign to each vertex the color that differs from the color of its parent in the depth-first search tree, assigning colors in a preorder traversal of the depth-first-search tree. If there exists an edge connecting current vertex to a previously-colored vertex with the same color, then we can say that the graph is not bipartite

Output: 

Not a Biparte Graph

 
The time complexity of above solution is O(n + m) where n is number of vertices and e is number of edges in the graph. Please note that O(m) may vary between O(1) and O(n2), depending on how dense the graph is.

*/

// Data structure to store graph edges
struct Edge {
    int src, dest;
};

// Class to represent a graph object
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
        for (int i = 0; i < edges.size(); i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }
    // Destructor
    ~Graph() {
        delete[] adjList;
    }
};

// Perform DFS on graph starting from vertex v
bool DFS(Graph const &graph, int v, vector<bool> &discovered,
            vector<int> &color)
{
    // do for every edge (v -> u)
    for (int u : graph.adjList[v])
    {
        // if vertex u is explored for first time
        if (!discovered[u])
        {
            // mark current node as discovered
            discovered[u] = true;

            // set color as opposite color of parent node
            color[u] = !color[v];

            // if DFS on any subtree rooted at v
            // we return false
            if (!DFS(graph, u, discovered, color))
                return false;
        }
        // if the vertex is already been discovered and color of vertex
        // u and v are same, then the graph is not Bipartite
        else if (color[v] == color[u]) {
            return false;
        }
    }

    return true;
}

// Determine if a given graph is Bipartite Graph using DFS
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {1, 2}, {2, 3}, {2, 8}, {3, 4}, {4, 6}, {5, 7},
        {5, 9}, {8, 9}, {2, 4}
        // if we remove 2->4 edge, graph is becomes Bipartite
    };

    // Number of nodes in the graph
    int N = 10;

    // create a graph from edges
    Graph graph(edges, N);

    // stores vertex is discovered or not
    vector<bool> discovered(N);

    // stores color 0 or 1 of each vertex in BFS
    vector<int> color(N);

    // mark source vertex as discovered and
    // set its color to 0
    discovered[0] = true, color[0] = 0;

    // start DFS traversal from any node as graph
    // is connected and undirected
    if (DFS(graph, 1, discovered, color))
        cout << "Bipartite Graph";
    else
        cout << "Not a Bipartite Graph";

    return 0;
}