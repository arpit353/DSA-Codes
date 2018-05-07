#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

/*

The shortest distance of source vertex 7 to


vertex 0 is  6 (7 —> 0)
vertex 1 is -2 (7 —> 5 —> 1)
vertex 2 is -6 (7 —> 5 —> 1 —> 2)
vertex 3 is  4 (7 —> 3)
vertex 4 is -1 (7 —> 5 —> 1 —> 4)
vertex 5 is -4 (7 —> 5)
vertex 6 is  6 (7 —> 5 —> 1 —> 6)

We know that a Topological Sort of a directed acyclic graph is a linear ordering of its vertices such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering.

We can use topological sort to solve this problem. When we consider a vertex u in topological order, it is guaranteed that we have considered every incoming edge to it. Now for each vertex v of the DAG in the topological order, we relax cost of its outgoing edges (update shortest path information). In order words since we have already found shortest path to vertex v, we can use that info to update shortest path of all its adjacent vertices. i.e.

for each vertex u in topological order
    for each edge (u, v) with weight w
        if distance[u] + w < distance[v]
            distance[v] = distance[u] + w

Output:

Shortest distance of source vertex 7 to vertex 0 is 6
Shortest distance of source vertex 7 to vertex 1 is -2
Shortest distance of source vertex 7 to vertex 2 is -6
Shortest distance of source vertex 7 to vertex 3 is 4
Shortest distance of source vertex 7 to vertex 4 is -1
Shortest distance of source vertex 7 to vertex 5 is -4
Shortest distance of source vertex 7 to vertex 6 is 6
Shortest distance of source vertex 7 to vertex 7 is 0

*/

// data structure to store graph edges
struct Edge {
    int src, dest, weight;
};

// class to represent a graph object
class Graph
{
public:
    // An array of vectors to represent adjacency list
    vector<Edge> *adjList;

    // Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // allocate memory
        adjList = new vector<Edge>[N];

        // add edges to the directed graph
        for (Edge const &edge: edges)
        {
            adjList[edge.src].push_back(edge);
        }
    }
};

// Perform DFS on graph and set departure time of all
// vertices of the graph
int DFS(Graph const &graph, int v, vector<bool> &discovered,
        vector<int> &departure, int& time)
{
    // mark current node as discovered
    discovered[v] = true;

    // set arrival time - not needed
    // time++;

    // do for every edge (v -> u)
    for (Edge e : graph.adjList[v])
    {
        int u = e.dest;
        // u is not discovered
        if (!discovered[u])
            DFS(graph, u, discovered, departure, time);
    }

    // ready to backtrack
    // set departure time of vertex v
    departure[time] = v;
    time++;
}

// The function performs topological sort on a given DAG
// and then finds out the shortest distance of all vertices
// from given source by running one pass of Bellman-Ford
// algorithm on edges of vertices in topological order
void findShortestDistance(Graph const& graph, int source, int N)
{
    // departure[] stores vertex number having its departure
    // time equal to the index of it
    vector<int> departure(N, -1);

    // stores vertex is discovered or not
    vector<bool> discovered(N);
    int time = 0;

    // perform DFS on all undiscovered vertices
    for (int i = 0; i < N; i++)
        if (!discovered[i])
            DFS(graph, i, discovered, departure, time);

    vector<int> cost(N, INT_MAX);
    cost[source] = 0;

    // Process the vertices in topological order i.e. in order
    // of their decreasing departure time in DFS
    for (int i = N - 1; i >= 0; i--)
    {
        // for each vertex in topological order,
        // relax cost of its adjacent vertices
        int v = departure[i];
        for (Edge e : graph.adjList[v])
        {
            // edge e from v to u having weight w
            int u = e.dest;
            int w = e.weight;

            // if the distance to the destination u can be shortened by
            // taking the edge vu, then update cost to the new lower value
            if (cost[v] != INT_MAX && cost[v] + w < cost[u])
                cost[u] = cost[v] + w;
        }
    }

    // print shortest paths
    for (int i = 0; i < N; i++)
    {
        cout << "Shortest distance of source vertex " << source <<
          " to vertex " << i << " is " << setw(2) << cost[i] << '\n';
    }
}

// Find the cost of Shortest Path in DAG
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges =
    {
        {0, 6, 2}, {1, 2, -4}, {1, 4, 1}, {1, 6, 8}, {3, 0, 3}, {3, 4, 5},
        {5, 1, 2}, {7, 0, 6}, {7, 1, -1}, {7, 3, 4}, {7, 5, -4}
    };

    // Number of nodes in the graph
    int N = 8;

	// create a graph from edges
	Graph graph(edges, N);

    // source vertex
    int source = 7;

    // find Shortest distance of all vertices from given source
    findShortestDistance(graph, source, N);

    return 0;
}
