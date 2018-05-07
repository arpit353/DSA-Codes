#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

Given a directed graph, check if it is strongly connected or not. A directed graphs is said to be strongly connected if every vertex is reachable from every other vertex.

For example, below graph is strongly connected as path exists between all pairs of vertices

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
        for (unsigned int i = 0; i < edges.size(); i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            adjList[src].push_back(dest);
        }
    }

    // Destructor
    ~Graph() {
        delete[] adjList;
    }
};

// Function to perform DFS Traversal
void DFS(Graph const &graph, int v, vector<bool> &visited)
{
    // mark current node as visited
    visited[v] = true;

    // do for every edge (v -> u)
    for (int u : graph.adjList[v])
    {
        // u is not visited
        if (!visited[u])
            DFS(graph, u, visited);
    }
}

// check if graph is strongly connected or not
bool check(Graph const& graph, int N)
{
    // do for every vertex
    for (int i = 0; i < N; i++)
    {
           // stores vertex is visited or not
        vector<bool> visited(N);

        // start DFS from first vertex
        DFS(graph, i, visited);

        // If DFS traversal doesn’t visit all vertices,
        // then graph is not strongly connected
        if (find(visited.begin(), visited.end(), false)
                != visited.end())
            return false;
    }
    return true;
}

// main function
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 4},
        {3, 1}, {3, 2}, {4, 3}
    };

    // Number of nodes in the graph
    int N = 5;

    // create a graph from given edges
    Graph graph(edges, N);

    // check if graph is not strongly connected or not
    if (check(graph, N))
        cout << "Graph is Strongly Connected";
    else
        cout << "Graph is not Strongly Connected";

    return 0;
}
