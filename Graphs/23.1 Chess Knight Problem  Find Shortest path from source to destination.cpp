#include <iostream>
#include <map>
#include <queue>
#include <climits>
using namespace std;
/*

Given a chess board, find the shortest distance (minimum number of steps) taken by a Knight to reach given destination from given source.

For example,
Input: N = 8 (8 x 8 board), Source = (7, 0) Destination  = (0, 7)

Output: Minimum number of steps required is 6

Explanation: The Knight’s movement can be demonstrated in figure below

chess-board
 
The idea is to use Breadth First Search (BFS) as it is a Shortest Path problem. Below is the complete algorithm.

1. Create an empty queue and enqueue source cell having
   distance 0 from source (itself)

2. do till queue is not empty

   a) Pop next unvisited node from queue

   b) If the popped node is destination node, return its distance

   c) else we mark current node as visited and for each of 8 possible
      movements for a knight, we enqueue each valid movement into the
      queue with +1 distance (min distance of given node from source
      = min distance of parent from source + 1)

A knight can move in 8 possible directions from a given cell as illustrated in below figure –
knight-movements

We can find all the possible locations the Knight can move to from the given location by using the array that stores the relative position of Knight movement from any location. For example, if the current location is (x, y), we can move to (x + row[k], y + col[k]) for 0 <= k <=7 using below array.

row[] = [ 2, 2, -2, -2, 1, 1, -1, -1 ]
col[] = [ -1, 1, 1, -1, 2, -2, 2, -2 ]

So, from position (x, y) Knight’s can move to:

(x + 2, y – 1)
(x + 2, y + 1)
(x – 2, y + 1)
(x – 2, y – 1)
(x + 1, y + 2)
(x + 1, y – 2)
(x – 1, y + 2)
(x – 1, y – 2)
 
Note that in BFS, all cells having shortest path as 1 are visited first, followed by their adjacent cells having shortest path as 1 + 1 = 2 and so on.. so if we reach any node in BFS, its shortest path = shortest path of parent + 1. So, the first occurrence of the destination cell gives us the result and we can stop our search there. It is not possible that the shortest path exists from some other cell for which we haven’t reached the given node yet. If any such path was possible, we would have already explored it

*/

#define N 8

// Below arrays details all 8 possible movements 
// for a knight
int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };

// Check if (x, y) is valid chess board coordinates
// Note that a knight cannot go out of the chessboard
bool valid(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N)
        return false;

    return true;
}

// queue node used in BFS
struct Node
{
    // (x, y) represents chess board coordinates
    // dist represent its minimum distance from the source
    int x, y, dist;

    // Node constructor
    Node(int x, int y, int dist = 0): x(x), y(y), dist(dist) {}

    // As we are using struct as a key in a std::map, 
    // we need to overload < operator
    // Alternatively we can use std::pair<int, int> as a key
    // to store coordinates of the matrix in the map

    bool operator<(const Node& o) const
    {
        return x < o.x || (x == o.x && y < o.y);
    }
};

// Find minimum number of steps taken by the knight 
// from source to reach destination using BFS
int BFS(Node src, Node dest)
{
    // map to check if matrix cell is visited before or not
    map<Node, bool> visited;
    
    // create a queue and enqueue first node
    queue<Node> q;
    q.push(src);

    // run till queue is not empty
    while (!q.empty())
    {
        // pop front node from queue and process it
        Node node = q.front();
        q.pop();

        int x = node.x;
        int y = node.y;
        int dist = node.dist;
        
        // if destination is reached, return distance
        if (x == dest.x && y == dest.y)
            return dist;

        // Skip if location is visited before
        if (!visited.count(node))
        {
            // mark current node as visited
            visited[node] = true;

            // check for all 8 possible movements for a knight
            // and enqueue each valid movement into the queue
            for (int i = 0; i < 8; ++i) 
            {
                // Get the new valid position of Knight from current
                // position on chessboard and enqueue it in the  
                // queue with +1 distance
                int x1 = x + row[i];
                int y1 = y + col[i];

                if (valid(x1, y1))
                    q.push({x1, y1, dist + 1});
            }
        }
    }

    // return INFINITY if path is not possible
    return INT_MAX;
}

// main function
int main()
{
    // source coordinates
    Node src = {0, 7};

    // destination coordinates
    Node dest = {7, 0};

    cout << "Minimum number of steps required is " << BFS(src, dest);

    return 0;
}