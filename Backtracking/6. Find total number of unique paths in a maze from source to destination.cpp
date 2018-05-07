#include <iostream>
#include <cstring>
using namespace std;
#define N 4

/*
Find the total number of unique paths which the robot can take in a given maze to reach the destination from given source.

Positions in the maze will either be open or blocked with an obstacle. The robot can only move to positions without obstacles i.e. solution should find paths which contain only cells which are open. Retracing the 1 or more cells back and forth is not considered a new path. The set of all cells covered in a single path should be unique from other paths. At any given moment, the robot can only move 1 step in one of 4 directions. Valid moves are:

Go North: (x, y) –> (x – 1, y)
Go West: (x, y) –> (x, y – 1)
Go South: (x, y) –> (x + 1, y)
Go East: (x, y) –> (x, y + 1)

For example, consider below maze in the form of a binary matrix where 0 represents an blocked cell and 1 represents an open cell.

[ 1 1 1 1 ]
[ 1 1 0 1 ]
[ 0 1 0 1 ]
[ 1 1 1 1 ]

We have to find number of unique paths from source to destination. Above maze contains 4 unique paths (marked in blue color)

[ 1 1 1 1 ]      [ 1 1 1 1 ]      [ 1 1 1 1 ]      [ 1 1 1 1 ]
[ 1 1 0 1 ]      [ 1 1 0 1 ]      [ 1 1 0 1 ]      [ 1 1 0 1 ]
[ 0 1 0 1 ]      [ 0 1 0 1 ]      [ 0 1 0 1 ]      [ 0 1 0 1 ]
[ 1 1 1 1 ]      [ 1 1 1 1 ]      [ 1 1 1 1 ]      [ 1 1 1 1 ]

The robot should search for a path from the starting position to the goal position until it finds one or until it exhausts all possibilities. We can easily achieve this with the help of Backtracking. We start from given source cell in the matrix and explore all four paths possible and recursively check if they will leads to the destination or not. We update the unique path count whenever destination cell is reached. If a path doesn’t reach destination or we have explored all possible routes from the current cell, we backtrack. To make sure that the path is simple and doesn’t contain any cycles, we keep track of cells involved in current path in an matrix and before exploring any cell, we ignore the cell if it is already covered in current path.

*/

// Check if cell (x, y) is valid or not
bool isValidCell(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N)
        return false;

    return true;
}

void countPaths(int maze[N][N], int x, int y, int visited[N][N], int& count)
{
    // if destination (bottom-rightmost cell) is found, 
    // increment the path count
    if (x == N - 1 && y == N - 1) 
    {
        count++;
        return;
    }

    // mark current cell as visited
    visited[x][y] = 1;
    
    // if current cell is a valid and open cell, 
    if (isValidCell(x, y) && maze[x][y]) 
    {
        // go down (x, y) --> (x + 1, y)
        if (x + 1 < N && !visited[x + 1][y])
            countPaths(maze, x + 1, y, visited, count);
            
        // go up (x, y) --> (x - 1, y)
        if (x - 1 >= 0 && !visited[x - 1][y])
            countPaths(maze, x - 1, y, visited, count);
            
        // go right (x, y) --> (x, y + 1)
        if (y + 1 < N && !visited[x][y + 1])
            countPaths(maze, x, y + 1, visited, count);
            
        // go left (x, y) --> (x, y - 1)
        if (y - 1 >= 0 && !visited[x][y - 1])
            countPaths(maze, x, y - 1, visited, count);
    }
    
    // backtrack from current cell and remove it from current path
    visited[x][y] = 0;
}

int main()
{
    int maze[N][N] = 
    {
        { 1, 1, 1, 1 },
        { 1, 1, 0, 1 },
        { 0, 1, 0, 1 },
        { 1, 1, 1, 1 }
    };

    // stores number of unique paths from source to destination
    int count = 0;

    // 2D matrix to keep track of cells involved in current path
    int visited[N][N];
    memset(visited, 0, sizeof visited);
    
    // start from source cell (0, 0)
    countPaths(maze, 0, 0, visited, count);
    
    cout << "Total number of unique paths are " << count;
    
    return 0;
}
