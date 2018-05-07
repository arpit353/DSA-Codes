#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Data structure to store graph edges
struct Edge {
    int src, dest;
};

// Class to represent a graph object
class Graph
{
public:
    // A array of vectors to represent adjacency list
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
    
    // Destructor
    ~Graph() {
        delete[] adjList;
    }
};

// Perform BFS recursively on graph
void recursiveBFS(Graph const &graph, queue<int> &q, 
                    vector<bool> &discovered)
{
    if (q.empty())
        return;

    // pop front node from queue and print it
    int v = q.front();
    q.pop();
    cout << v << " ";

    // do for every edge (v -> u)
    for (int u : graph.adjList[v])
    {
        if (!discovered[u])
        {
            // mark it discovered and push it into queue
            discovered[u] = true;
            q.push(u);
        }
    }

    recursiveBFS(graph, q, discovered);
}

// Recursive C++ implementation of Breadth first search
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9}, 
        {5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
        // vertex 0, 13 and 14 are single nodes
    };

    // Number of nodes in the graph
    int N = 15;

    // create a graph from edges
    Graph graph(edges, N);

    // stores vertex is discovered or not
    vector<bool> discovered(N, false);

    // create a queue used to do BFS
    queue<int> q;

    // Do BFS traversal from all undiscovered nodes to
    // cover all unconnected components of graph
    for (int i = 0; i < N; i++) {
        if (discovered[i] == false)
        {
            // mark source vertex as discovered
            discovered[i] = true;

            // push source vertex into the queue
            q.push(i);

            // start BFS traversal from vertex i
            recursiveBFS(graph, q, discovered);
        }
    }

    return 0;
}