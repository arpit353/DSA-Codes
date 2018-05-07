#include <iostream>
#include <vector>
using namespace std;

/*

Given a graph, find arrival & departure time of its vertices in DFS. Arrival Time is the time at which the vertex was explored for the first time in the DFS and Departure Time is the time at which we have explored all the neighbors of the vertex and we are ready to backtrack.

Below directed graph has two connected components. Right hand side shows Arrival Time & Departure Time of Vertices when DFS is starting from vertex 0.

The idea is to run DFS. Before exploring any adjacent nodes of any vertex in DFS, we note the arrival time of that vertex and after exploring all adjacent nodes of the vertex, we note its departure time. After the DFS call is over i.e. we have discovered all the vertices of the graph, we print the arrival and departure time of the vertices.

Output: 

Vertex 0 (0, 11)
Vertex 1 (1, 2)
Vertex 2 (3, 10)
Vertex 3 (4, 7)
Vertex 4 (8, 9)
Vertex 5 (5, 6)
Vertex 6 (12, 15)
Vertex 7 (13, 14)

 
The time complexity of DFS traversal is O(n + m) where n is number of vertices and e is number of edges in the graph. Please note that O(m) may vary between O(1) and O(n2), depending on how dense the graph is.

Applications of finding Arrival and Departure Time –

Topological sorting in a DAG(Directed Acyclic Graph)
Finding 2-(edge or vertex)-connected components.
Finding 3-(edge or vertex)-connected components.
Finding the bridges of a graph.
Finding biconnectivity in graphs
Detecting Cycle in a Directed Graph
Tarjan’s Algorithm to find Strongly Connected Components and many more..

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

    // Destructor
    ~Graph() {
        delete[] adjList;
    }
};

// Function to perform DFS Traversal
int DFS(Graph const &graph, int v, vector<bool> &discovered,
    vector<int> &arrival, vector<int> &departure, int &time)
{    
    // set arrival time of vertex v
    arrival[v] = ++time;
 
    // mark vertex as discovered
    discovered[v] = true;
     
    for (int i : graph.adjList[v])
    if (!discovered[i])
        DFS(graph, i, discovered, arrival, departure, time);
 
    // set departure time of vertex v
    departure[v] = ++time;
}

// main function
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges = { 
        {0, 1}, {0, 2}, {2, 3}, {2, 4}, {3, 1}, {3, 5}, 
        {4, 5}, {6, 7}
    };

    // Number of nodes in the graph
    int N = 8;

    // create a graph from given edges
    Graph graph(edges, N);

    // vector to store arrival time of vertex
    vector<int> arrival(N);

    // vector to store departure time of vertex
    vector<int> departure(N);
    
    // Mark all the vertices as not discovered
    vector<bool> discovered(N);
    int time = -1;
 
    // Do DFS traversal from all undiscovered nodes to 
    // cover all unconnected components of graph
    for (int i = 0; i < N; i++)
    if (!discovered[i])
        DFS(graph, i, discovered, arrival, departure, time);
    
    // print arrival and departure time of each 
    // vertex in DFS
    for (int i = 0; i < N; i++)
        cout << "Vertex " << i << " (" << arrival[i]
             << ", " << departure[i] << ")" << endl;

    return 0;
}