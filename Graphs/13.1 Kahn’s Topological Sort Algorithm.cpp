#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*

Given a directed acyclic graph (DAG), print it in Topological order using Kahn’s Topological Sort algorithm. If the DAG has more than one topological ordering, print any of them.

A Topological Sort or Topological Ordering of a directed graph is a linear ordering of its vertices such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering. A topological ordering is possible if and only if the graph has no directed cycles, i.e. if the graph is DAG.
 
For example, consider below graph:

Kahn's Topological Sort Algorithm

Above graph has many valid topological ordering of vertices like,


7, 5, 3, 1, 4, 2, 0, 6
7, 5, 1, 2, 3, 4, 0, 6
5, 7, 3, 1, 0, 2, 6, 4
3, 5, 7, 0, 1, 2, 6, 4
5, 7, 3, 0, 1, 4, 6, 2
7, 5, 1, 3, 4, 0, 6, 2
5, 7, 1, 2, 3, 0, 6, 4
3, 7, 0, 5, 1, 4, 2, 6

.. and many more

 
Note that for every directed edge u -> v, u comes before v in the ordering. For example, the pictorial representation of the topological order [7, 5, 3, 1, 4, 2, 0, 6] is:

 
Kahn's Topological Sort Algorithm

 
In the previous post, we have seen how to print topological order of a graph using Depth First Search (DFS) algorithm. In this post, Kahn’s Topological Sort algorithm is introduced which provides a efficient way to print topological order of a graph.

 
Kahn’s Topological Sort Algorithm works by finding vertices which have no incoming edges and removing all outgoing edges from these vertices. Below is psedocode for Kahn’s Topological Sort Algorithm taken from Wikipedia –

 

Kahn’s-Algorithm (graph)

L -> Empty list that will contain the sorted elements
S -> Set of all vertices with no incoming edges (i.e. having indegree 0)

while S is non-empty do
    remove a vertex n from S
    add n to tail of L
    for each vertex m with an edge e from n to m do
        remove edge e from the graph
        if m has no other incoming edges then
            insert m into S

if graph has edges then
    return report “graph has at least one cycle”
else
    return L “a topologically sorted order”

 

Note that a DAG has at least one such vertex which has no incoming edges.

How can we remove an edge from the graph or check if a vertex has no other incoming edge in constant time?
 
The idea is to maintain in-degree information of all graph vertices in a map or an array (say indegree[]) for constant time operations. Here, indegree[m] will store number of incoming edges to vertex m.

If vertex m has no incoming edge and is ready to get processed, its indegree will be 0 i.e. indegree[m] = 0.
 
To remove an edge from n to m from the graph, we decrement indegree[m] by 1.
 
Below is C++/Java implementation of Kahn’s Topological Sort Algorithm:

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

    // stores indegree of a vertex
    vector<int> indegree;

    // Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // allocate memory
        adjList = new vector<int>[N];
 
        // initalize indegree
        vector<int> temp(N, 0);
        indegree = temp;

        // add edges to the directed graph
        for (unsigned i = 0; i < edges.size(); i++)
        {
            int src = edges[i].src;      // source
            int dest = edges[i].dest;    // destination

            // add an edge from source to destination
            adjList[src].push_back(dest);
            
            // increment in-degree of destination vertex by 1
            indegree[dest]++;
        }
    }

    // Destructor
    ~Graph() {
        delete[] adjList;
    }
};

// performs Topological Sort on a given DAG
bool doTopologicalSort(Graph const &graph, list<int> &L, int N)
{
    vector<int> indegree = graph.indegree;

    // Set of all nodes with no incoming edges
    list<int> S;
    for (int i = 0; i < N; i++)
        if (!indegree[i])
            S.push_back(i);

    while (!S.empty())
    {
        // remove a node n from S
        int n = S.back();
        S.pop_back();

        // add n to tail of L
        L.push_back(n);

        for (int m : graph.adjList[n])
        {
            // remove edge from n to m from the graph
            indegree[m] -= 1;

            // if m has no other incoming edges then
            // insert m into S
            if (!indegree[m])
                S.push_back(m);
        }
    }

    // if graph has edges then graph has at least one cycle
    for (int u = 0; u < N; u++)
        for (int i : graph.adjList[u])
            if (indegree[i])
                return false;

    return true;
}

int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges =
    {
        { 0, 6 }, { 1, 2 }, { 1, 4 }, { 1, 6 }, { 3, 0 }, { 3, 4 },
        { 5, 1 }, { 7, 0 }, { 7, 1 }
    };

    // Number of nodes in the graph
    int N = 8;

    // create a graph from edges
    Graph graph(edges, N);

    // Empty list that will contain the sorted elements
    list<int> L;

    // Perform Topological Sort
    if (doTopologicalSort(graph, L, N)) {
        // print topological order
        for (int i: L)
            cout << i << " ";
    } else {
        cout << "Graph has at least one cycle. "
                 "Topological sorting is not possible";
    }

    return 0;
}