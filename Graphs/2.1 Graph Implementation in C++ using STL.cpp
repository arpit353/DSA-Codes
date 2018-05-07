#include <iostream>
#include <vector>
using namespace std;

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
        for (unsigned i = 0; i < edges.size(); i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            // insert at the end
            adjList[src].push_back(dest);

            // Uncomment below line for undirected graph
            // adjList[dest].push_back(src);
        }
    }

    // Destructor
    ~Graph() {
        delete[] adjList;
    }
};

// print adjacency list representation of graph
void printGraph(Graph const& graph, int N)
{
    for (int i = 0; i < N; i++)
    {
        // print current vertex number
        cout << i << " --> ";

        // print all neighboring vertices of vertex i
        for (int v : graph.adjList[i])
            cout << v << " ";
        cout << endl;
    }
}

// Graph Implementation using STL
int main()
{
    // vector of graph edges as per above diagram.
    // Please note that initialization vector in below format will
    // work fine in C++11, C++14, C++17 but will fail in C++98.
    vector<Edge> edges =
    {
        { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
        { 3, 2 }, { 4, 5 }, { 5, 4 }
    };

    // Number of nodes in the graph
    int N = 6;

    // construct graph
    Graph graph(edges, N);

    // print adjacency list representation of graph
    printGraph(graph, N);

    return 0;
}
