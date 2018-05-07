#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*

When we do a BFS from any vertex v in an undirected graph, we may encounter cross-edge that points to a previously discovered vertex that is neither an ancestor nor a descendant of current vertex. Each “cross edge” defines a cycle in an undirected graph. If the cross edge is x -> y then since y is already discovered, we have a path from v to y (or from y to v since the graph is undirected) where v is the starting vertex of BFS. So we can say that we have a path v ~~ x ~ y ~~ v. that forms a cycle. (Here ~~ represents one more more edges in the path and ~ represents a direct edge).

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
        for (unsigned i = 0; i < edges.size(); i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }
};

// node to store vertex and its parent info in BFS
struct Node
{
    int v, parent;
};

// Perform BFS on graph starting from vertex src and
// returns true of cycle is found in the graph
bool BFS(Graph const &graph, int src, int N)
{
    // stores vertex is discovered or not
    vector<bool> discovered(N);

    // mark source vertex as discovered
    discovered[src] = true;

    // create a queue used to do BFS and
    // push source vertex into the queue
    queue<Node> q;
    q.push({src, -1});

    // run till queue is not empty
    while (!q.empty())
    {
        // pop front node from queue and print it
        Node node = q.front();
        q.pop();

        // do for every edge (v -> u)
        for (int u : graph.adjList[node.v])
        {
            if (!discovered[u])
            {
                // mark it discovered
                discovered[u] = true;

                // construct the queue node containing info
                // about vertex and push it into the queue
                q.push({ u, node.v });
            }

            // u is discovered and u is not a parent
            else if (u != node.parent)
            {
                // we found a cross-edge ie. cycle is found
                return true;
            }
        }
    }

    // No cross-edges found in the graph
    return false;
}

// Check if an undirected graph contains cycle or not
int main()
{
    // initialize edges as per above diagram
    vector<Edge> edges =
    {
        {1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
        {5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}, {6, 10}
        // edge (6->10) introduces a cycle in the graph
    };

    // Number of nodes in the graph
    int N = 13;

	// create a graph from given edges
	Graph graph(edges, N);

    // Do BFS traversal in connected components of graph
    if (BFS(graph, 1, N))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain any cycle";

    return 0;
}