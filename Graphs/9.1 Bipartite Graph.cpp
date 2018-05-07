#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*

Given a graph, check if given graph is bipartite graph or not. A bipartite graph (or bigraph) is a graph whose vertices can be divided into two disjoint sets U and V such that every edge connects a vertex in U to one in V.

Below graph is a Bipartite Graph as we can divide it into two sets U and V with every edge having one end point in set U and the other in set V

It is possible to test whether a graph is bipartite or not using breadth-first search algorithm. There are two ways to check for Bipartite graphs –

1. A graph is bipartite graph if and only if it is 2-colorable.
While doing BFS traversal, each node in the BFS tree is given the opposite color to its parent. If there exists an edge connecting current vertex to a previously-colored vertex with the same color, then we can safely conclude that the graph is not bipartite.

2. A graph is bipartite graph if and only if it does not contain an odd cycle.
If a graph contains an odd cycle, we cannot divide the graph such that every adjacent vertex has different color. To check if a given graph is contains odd-cycle or not, we do a breadth-first search starting from an arbitrary vertex v. If in the BFS, we find an edge, both of whose end-points are in the same level, then the graph is not Bipartite and odd-cycle is found. Here, level of a vertex is its minimum distance from the starting vertex v. So, odd-level vertices will form one set and even-level vertices will form another.

Please note that if the graph has many connected components and each component bipartite, them the graph is bipartite graph. Below code assume that given graph is connected and checks if the graph contains an odd cycle or not.

Output:

Bipartite Graph

The time complexity of above solution is O(n + m) where n is number of vertices and e is number of edges in the graph. Please note that O(m) may vary between O(1) and O(n2), depending on how dense the graph is.

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

// Perform BFS on graph starting from vertex v    
bool BFS(Graph const &graph, int v, int N)
{
    // stores vertex is discovered or not
    vector<bool> discovered(N);
    
    // stores level of each vertex in BFS
    vector<int> level(N);
    
    // mark source vertex as discovered and 
    // set its level to 0
    discovered[v] = true, level[v] = 0;
    
    // create a queue to do BFS and enqueue 
    // source vertex in it
    queue<int> q;
    q.push(v);
 
    // run till queue is not empty
    while (!q.empty())
    {
        // pop front node from the queue
        v = q.front();
        q.pop();

        // do for every edge (v -> u)
        for (int u : graph.adjList[v])
        {
            // if vertex u is explored for first time
            if (!discovered[u])
            {
                // mark it discovered
                discovered[u] = true;
                
                // set level as level of parent node + 1
                level[u] = level[v] + 1;
                
                // push the vertex into the queue
                q.push(u);
            }
            
            // if the vertex is already been discovered and
            // level of vertex u and v are same, then the 
            // graph contains an odd-cycle & is not biparte
            else if (level[v] == level[u])
                return false;
        }
    }
    
    return true;
}

// Determine if a given graph is Bipartite Graph or not
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {1, 2}, {2, 3}, {2, 8}, {3, 4}, {4, 6}, {5, 7}, 
        {5, 9}, {8, 9}
        // if we add 2->4 edge, graph is becomes non-Bipartite
    };

    // Number of nodes in the graph
    int N = 10;

    // create a graph from edges
    Graph graph(edges, N);
    
    // Do BFS traversal starting from vertex 1
    if (BFS(graph, 1, N))
        cout << "Bipartite Graph";
    else 
        cout << "Not a Bipartite Graph";
    
    return 0;
}