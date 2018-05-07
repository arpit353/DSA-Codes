#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

/*

Given a graph, find if it is k-colorable or not and print all possible configuration of assignment of colors to its vertices.


The vertex coloring is a way of coloring the vertices of a graph such that no two adjacent vertices share the same color. A coloring using at most k colors is called a (proper) k-coloring and graph that can be assigned a (proper) k-coloring is k-colorable.

For example, consider below graph,

Please note that we can’t color the above graph using 2 colors. i.e. it is not 2-colorable.
  
We can use backtracking to solve this problem. The idea is to try all possible combinations of colors for the first vertex in the graph and recursively explore remaining vertices to check if they will lead to the solution or not. If current configuration doesn’t result in solution, we backtrack. Note that we assign any color to a vertex only if its adjacent vertices share the different colors.

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
	vector<int> *adj;

	// Constructor
	Graph(vector<Edge> const &edges, int N)
	{
		// allocate memory
		adj = new vector<int>[N];

        // add edges to the undirected graph
        for (int i = 0; i < edges.size(); i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
    }
};

// string array to store colors (10-colorable graph)
string COLORS[] = {"", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE",
                "PINK", "BLACK", "BROWN", "WHITE", "PURPLE"};

// Function to check if it is safe to assign color c to vertex v
bool isSafe(Graph const &graph, vector<int> color, int v, int c)
{
    // check color of every adjacent vertex of v
    for (int u : graph.adj[v])
        if (color[u] == c)
            return false;

    return true;
}

void kColorable(Graph const &graph, vector<int> &color, int k, int v, int N)
{
    // if all colors are assigned, print the solution
    if (v == N)
    {
        for (int v = 0; v < N; v++)
            cout << setw(8) << left << COLORS[color[v]];
        cout << endl;

        return;
    }

    // try all possible combinations of available colors
    for (int c = 1; c <= k; c++)
    {
        // if it is safe to assign color c to vertex v
        if (isSafe(graph, color, v, c))
        {
            // assign color c to vertex v
            color[v] = c;

            // recurse for next vertex
            kColorable(graph, color, k, v + 1, N);

            // backtrack
            color[v] = 0;
        }
    }
}

// main function
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges =
    {
        {0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4}
    };

    // Number of vertices in the graph
    int N = 6;

    // create a graph from edges
    Graph g(edges, N);

    int k = 3;

    vector<int> color(N, 0);

    // print all k-colorable configurations of the graph
    kColorable(g, color, k, 0, N);

    return 0;
}

/*

Output: 

BLUE    GREEN   BLUE    RED     RED     GREEN
BLUE    GREEN   GREEN   BLUE    RED     GREEN
BLUE    GREEN   GREEN   RED     RED     GREEN
BLUE    RED     BLUE    GREEN   GREEN   RED
BLUE    RED     RED     BLUE    GREEN   RED
BLUE    RED     RED     GREEN   GREEN   RED
GREEN   BLUE    BLUE    GREEN   RED     BLUE
GREEN   BLUE    BLUE    RED     RED     BLUE
GREEN   BLUE    GREEN   RED     RED     BLUE
GREEN   RED     GREEN   BLUE    BLUE    RED
GREEN   RED     RED     BLUE    BLUE    RED
GREEN   RED     RED     GREEN   BLUE    RED
RED     BLUE    BLUE    GREEN   GREEN   BLUE
RED     BLUE    BLUE    RED     GREEN   BLUE
RED     BLUE    RED     GREEN   GREEN   BLUE
RED     GREEN   GREEN   BLUE    BLUE    GREEN
RED     GREEN   GREEN   RED     BLUE    GREEN
RED     GREEN   RED     BLUE    BLUE    GREEN


*/