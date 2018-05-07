#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

Can we do better?

We can say that G is strongly connected if

1. DFS(G, v) visits all vertices in graph G, then there exists path from v to every other vertex in G and

2. There exists a path from every other vertex in G to v

 
Proof:
For G to be strongly connected, there should exists a path from x -> y and from y -> x for any pair of vertices (x, y) in the graph.

If Point 1 and Point 2 are true,
We can reach x -> y by going from vertex x to vertex v (from pt. 2) and then from vertex v to vertex y (from pt. 1).
Similarly, we can reach y -> x by going from vertex y to vertex v (from pt. 2) and then from vertex v to vertex x (from pt. 1).

 
Complete Algorithm –

1. Start DFS(G, v) from a random vertex v of the graph G. If DFS(G, v) fails to reach every other vertex in the graph G, then there is some vertex u, such that there is no directed path from v to u, and thus G is not strongly connected. If it does reach every vertex, then there is a directed path from v to every other vertex in the graph G.

2. Reverse the direction of all edges in the directed graph G.

3. Again run a DFS starting from vertex v. If the DFS fails to reach every vertex, then there is some vertex u, such that in the original graph there is no directed path from u to v. On the other hand, if it does reach every vertex, then in the original graph there is a directed path from every vertex u to v.

Thus if G passes both DFS, it is strongly connected.


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
    // stores vertex is visited or not
    vector<bool> visited(N);
    
    // choose random starting point
    int v = 0;
    
    // run a DFS starting at v
    DFS(graph, v, visited);
 
    // If DFS traversal doesn't visit all vertices, 
    // then graph is not strongly connected
    if (find(visited.begin(), visited.end(), false) 
                != visited.end())
        return false;

    // reset visited vector
    fill(visited.begin(), visited.end(), false);
    
    // Reverse the direction of all edges in the 
    // directed graph
    vector<Edge> edges;    
    for (int i = 0; i < N; i++)
        for (int j : graph.adjList[i])
            edges.push_back({j, i});

    // Create a graph from reversed edges
    Graph gr(edges, N);

    // Again run a DFS starting at v
    DFS(gr, v, visited);

    // If DFS traversal doesn't visit all vertices, 
    // then graph is not strongly connected
    if (find(visited.begin(), visited.end(), false) 
                != visited.end() )
        return false;

    // if graph "passes" both DFSs, it is strongly connected
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