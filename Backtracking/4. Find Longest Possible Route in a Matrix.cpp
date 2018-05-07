#include <bits/stdc++.h>
using namespace std;

/*

Given a rectangular path in the form of binary matrix, find the length of longest possible route from source to destination position of the matrix by moving to only non-zero adjacent positions i.e. route can be formed from positions having their value as 1. Note there should not be any cycles in the output path.

For example, longest path from given source cell (0, 0) to destination cell (5, 7) for below matrix is of length 22.

(0, 0) -> (1, 0) -> (2, 0) -> (2, 1) -> (2, 2) -> (1, 2) -> (0, 2) ->
(0, 3) -> (0, 4) -> (1, 4) -> (1, 5) -> (2, 5) -> (2, 4) -> (3, 4) ->
(4, 4) -> (5, 4) -> (5, 5) -> (5, 6) -> (4, 6) -> (4, 7) -> (4, 8) ->
(5, 8) -> (5, 7)

We can use Backtracking to solve this problem. We start from given source cell in the matrix and explore all four paths possible and recursively check if they will leads to the destination or not. We have to keep track of current distance of a cell from the source. We update the value of longest path found so far whenever destination cell is reached. If a path doesn’t reach destination or we have explored all possible routes from the current cell, we backtrack. To make sure that the path is simple and doesn’t contain any cycles, we keep track of cells involved in current path in an matrix and before exploring any cell, we ignore the cell if it is already covered in current path.
*/


// M x N matrix
#define M 10
#define N 10

// check if it is possible to go to position (x, y) from 
// current position. The function returns false if the cell
// has value 0 or it is already visited.
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

// Find Longest Possible Route in a Matrix mat from source 
// cell (0, 0) to destination cell (x, y)
// max_dist is passed by reference and stores length of 
// longest path from source to destination found so far
// dist maintains length of path from source cell to 
// current cell (i, j)
void findLongestPath(int mat[M][N], int visited[M][N], int i,
				int j, int x, int y, int& max_dist, int dist)
{
	// if destination is found, update max_dist
	if (i == x && j == y) 
	{
		max_dist = max(dist, max_dist);
		return;
	}
	
	// set (i, j) cell as visited
	visited[i][j] = 1;
	
	// go to bottom cell
	if (isValid(i + 1, j) && isSafe(mat, visited, i + 1, j))
		findLongestPath(mat, visited, i + 1, j, x, y, 
			max_dist, dist + 1);

	// go to right cell			
	if (isValid(i, j + 1) && isSafe(mat, visited, i, j + 1))
		findLongestPath(mat, visited, i, j + 1, x, y, 
			max_dist, dist + 1);
	
	// go to top cell
	if (isValid(i - 1, j) && isSafe(mat, visited, i - 1, j))
		findLongestPath(mat, visited, i - 1, j, x, y, 
						max_dist, dist + 1);
	
	// go to left cell
	if (isValid(i, j - 1) && isSafe(mat, visited, i, j - 1))
		findLongestPath(mat, visited, i, j - 1, x, y, 
						max_dist, dist + 1);
	
	// Backtrack - Remove (i, j) from visited matrix
	visited[i][j] = 0;
}

int main()
{
	// input matrix
	int mat[M][N] = 
	{
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
		{ 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
	};

	// construct a matrix to keep track of visited cells
	int visited[M][N];
	memset(visited, 0, sizeof visited);
	
	int max_dist = 0;
	findLongestPath(mat, visited, 0, 0, 5, 7, max_dist, 0);

	cout << "Maximum length path is " << max_dist;

	return 0;
}