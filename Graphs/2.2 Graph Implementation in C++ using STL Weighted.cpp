#include <iostream>
#include <vector>
using namespace std;

// data structure to store graph edges
struct Edge {
    int src, dest, weight;
};

// class to represent a graph object
class Graph
{
    public:
    // An array of vectors to represent adjacency list
    vector<pair<int, int>> *adjList;
 
    // Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // allocate memory
        adjList = new vector<pair<int, int>>[N];

        // add edges to the directed graph
        for (unsigned i = 0; i < edges.size(); i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;
            int weight = edges[i].weight;
            
            // insert at the end
            adjList[src].push_back(make_pair(dest, weight));
            
            // Uncomment below line for undirected graph
            // adjList[dest].push_back(make_pair(src, weight));
        }
    }

    // Destructor
    ~Graph() {
        delete[] adjList;
    }
};

// print adjacency list representation of graph
void printGraph(Graph const &graph, int N)
{
    for (int i = 0; i < N; i++)
    {
        // print all neighboring vertices of given vertex
        for (pair<int, int> v : graph.adjList[i])
            cout << "(" << i << ", " << v.first <<
                    ", " << v.second << ") ";
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
        // (x, y, w) -> edge from x to y having weight w
        { 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
        { 3, 2, 10 }, { 4, 5, 1 }, { 5, 4, 3 }
    };
    
    // Number of nodes in the graph
    int N = 6;

    // construct graph
    Graph graph(edges, N);

    // print adjacency list representation of graph
    printGraph(graph, N);

    return 0;
}