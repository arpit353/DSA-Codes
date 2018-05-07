#include <iostream>
#include <vector>
using namespace std;

/*

Given a Directed Acyclic Graph (DAG), print it in topological order using Topological Sort Algorithm. If the DAG has more than one topological ordering, output any of them.

A Topological Sort or topological ordering of a directed graph is a linear ordering of its vertices such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering. A topological ordering is possible if and only if the graph has no directed cycles, i.e. if the graph is DAG.

The graph has many valid topological ordering of vertices like,

5, 7, 3, 1, 0, 2, 6, 4
3, 5, 7, 0, 1, 2, 6, 4
5, 7, 3, 0, 1, 4, 6, 2
7, 5, 1, 3, 4, 0, 6, 2
5, 7, 1, 2, 3, 0, 6, 4
3, 7, 0, 5, 1, 4, 2, 6
etc.

We can use Depth First Search (DFS) to implement Topological Sort Algorithm. The idea is to order the vertices in order of their decreasing Departure Time of Vertices in DFS and we will get our desired topological sort.

 
How does this work?

We have already discussed about the relationship between all four types of edges involved in the DFS in the previous post. Below are the relation we have seen between the departure time for different types of edges involved in a DFS of directed graph –

 
Tree edge (u, v): departure[u] > departure[v]
Back edge (u, v): departure[u] < departure[v]
Forward edge (u, v): departure[u] > departure[v]
Cross edge (u, v): departure[u] > departure[v]

 
As we can see that for a tree edge, forward edge or cross edge (u, v), departure[u] is more than departure[v]. But only for back edge the relationship departure[u] < departure[v] is true. So it is guaranteed that if an edge (u, v) has departure[u] > departure[v], it is not a back-edge.

 
We know that in DAG no back-edge is present. So if we order the vertices in order of their decreasing departure time, we will get topological order of graph (every edge going from left to right).

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

        // add edges to the Directed graph
        for (unsigned i = 0; i < edges.size(); i++)
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

// Perform DFS on graph and set departure time of all
// vertices of the graph
int DFS(Graph const &graph, int v, vector<bool>
    &discovered, vector<int> &departure, int& time)
{
    // mark current node as discovered
    discovered[v] = true;

    // set arrival time
    time++;

    // do for every edge (v -> u)
    for (int u : graph.adjList[v])
    {
        // u is not discovered
        if (!discovered[u])
            DFS(graph, u, discovered, departure, time);
    }
    
    // ready to backtrack
    // set departure time of vertex v
    departure[time] = v;
    time++;
}

// performs Topological Sort on a given DAG
void doTopologicalSort(Graph const& graph, int N)
{
    // departure[] stores vertex number having its departure
    // time equal to the index of it
    vector<int> departure(2*N, -1);
    
    // Note if we had done the other way around i.e. fill
    // array with departure time by using vertex number
    // as index, we would need to sort the array later

    // stores vertex is discovered or not
    vector<bool> discovered(N);
    int time = 0;

    // perform DFS on all undiscovered vertices
    for (int i = 0; i < N; i++)
        if (!discovered[i])
            DFS(graph, i, discovered, departure, time);

    // Print the vertices in order of their decreasing
    // departure time in DFS i.e. in topological order
    for (int i = 2*N - 1; i >= 0; i--)
        if (departure[i] != -1)
            cout << departure[i] << " ";
}

// Topological Sort Algorithm for a DAG using DFS
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges =
    {
        {0, 6}, {1, 2}, {1, 4}, {1, 6}, {3, 0}, {3, 4},
        {5, 1}, {7, 0}, {7, 1}
    };

    // Number of nodes in the graph
    int N = 8;

    // create a graph from edges
    Graph graph(edges, N);

    // perform Topological Sort
    doTopologicalSort(graph, N);

    return 0;
}