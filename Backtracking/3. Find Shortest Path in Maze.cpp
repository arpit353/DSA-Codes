#include <bits/stdc++.h>
using namespace std;
 
/*

Given a maze in the form of the binary rectangular matrix, find length of the shortest path in maze from given source to given destination. The path can only be constructed out of cells having value 1 and at any given moment, we can only move one step in one of the four directions.

The Valid moves are:

Go Up: (x, y) –> (x – 1, y)
Go Left: (x, y) –> (x, y – 1)
Go Down: (x, y) –> (x + 1, y)
Go Right: (x, y) –> (x, y + 1)

 
For example, consider below binary matrix. If source = (0, 0) and destination = (7, 5), the shortest path from source to destination has length 12.

shortest path
 
To find shortest path in maze, we search for all possible paths in the maze from the starting position to the goal position until all possibilities are exhausted. We can easily achieve this with the help of backtracking. We start from given source cell in the matrix and explore all four paths possible and recursively check if they will leads to the destination or not. We update the minimum path length whenever destination cell is reached. If a path doesn’t reach destination or we have explored all possible routes from the current cell, we backtrack. To make sure that the path is simple and doesn’t contain any cycles, we keep track of cells involved in current path in an matrix and before exploring any cell, we ignore the cell if it is already covered in current path.


*/


// M x N matrix
#define M 10
#define N 10
 
// Check if it is possible to go to (x, y) from current position. The 
// function returns false if the cell has value 0 or already visited
bool isSafe(int mat[M][N], int visited[M][N], int x, int y)
{
	if (mat[x][y] == 0 || visited[x][y])
		return false;
 
	return true;
}
 
// if not a valid position, return false
bool isValid(int x, int y)
{
	if (x < M && y < N && x >= 0 && y >= 0)
		return true;
	 
	return false;
}
 
// Find Shortest Possible Route in a Matrix mat from source cell (0, 0) 
// to destination cell (x, y)
// min_dist is passed by reference and stores length of longest path 
// from source to destination found so far dist maintains length of 
// path from source cell to current cell (i, j)
void findShortestPath(int mat[M][N], int visited[M][N], int i, int j,
				int x, int y, int& min_dist, int dist)
{
	// if destination is found, update min_dist
	if (i == x && j == y) 
	{
		min_dist = min(dist, min_dist);
		return;
	}

	// set (i, j) cell as visited
	visited[i][j] = 1;
	 
	// go to bottom cell
	if (isValid(i + 1, j) && isSafe(mat, visited, i + 1, j))
		findShortestPath(mat, visited, i + 1, j, x, y, min_dist, dist + 1);
 
	// go to right cell		 
	if (isValid(i, j + 1) && isSafe(mat, visited, i, j + 1))
		findShortestPath(mat, visited, i, j + 1, x, y, min_dist, dist + 1);
	 
	// go to top cell
	if (isValid(i - 1, j) && isSafe(mat, visited, i - 1, j))
		findShortestPath(mat, visited, i - 1, j, x, y, min_dist, dist + 1);
	 
	// go to left cell
	if (isValid(i, j - 1) && isSafe(mat, visited, i, j - 1))
		findShortestPath(mat, visited, i, j - 1, x, y, min_dist, dist + 1);
	 
	// Backtrack - Remove (i, j) from visited matrix
	visited[i][j] = 0;
}
 
int main()
{
	int mat[M][N] = 
	{
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
		{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
	};
 
	// construct a matrix to keep track of visited cells
	int visited[M][N];

	// initially all cells are unvisited
	memset(visited, 0, sizeof visited);
	
	int min_dist = INT_MAX;
	findShortestPath(mat, visited, 0, 0, 7, 5, min_dist, 0);
 
	if(min_dist != INT_MAX)
		cout << "The shortest path from source to destination "
				"has length " << min_dist;
	else 
		cout << "Destination can't be reached from given source";
	
	return 0;
}