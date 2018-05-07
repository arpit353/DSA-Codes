#include <bits/stdc++.h>
using namespace std;

/*
Given a N x N matrix of positive integers, find a path from the first cell of the matrix to its last cell.

We can move exactly k steps from any cell in the matrix where k is the value of that cell. i.e. from any cell M[i][j] in the matrix M, we can move to location

M[i + M[i][j]][j] or
M[i – M[i][j]][j] or
M[i][j + M[i][j]] or
M[i][j – M[i][j]]

Note that we are not allowed to make any diagonal moves.
 
For example,

Input:

[ 7  1  3  5  3  6  1  1  7  5 ]
[ 2  3  6  1  1  6  6  6  1  2 ]
[ 6  1  7  2  1  4  7  6  6  2 ]
[ 6  6  7  1  3  3  5  1  3  4 ]
[ 5  5  6  1  5  4  6  1  7  4 ]
[ 3  5  5  2  7  5  3  4  3  6 ]
[ 4  1  4  3  6  4  5  3  2  6 ]
[ 4  4  1  7  4  3  3  1  4  2 ]
[ 4  4  5  1  5  2  3  5  3  5 ]
[ 3  6  3  5  2  2  6  4  2  1 ]

Output:

(0, 0) (7, 0) (3, 0) (9, 0) (6, 0) (2, 0) (8, 0) (4, 0) (4, 5) (0, 5) (6, 5)
(2, 5) (2, 1) (1, 1) (4, 1) (9, 1) (3, 1) (3, 7) (2, 7) (8, 7) (8, 2) (3, 2)
(3, 9) (7, 9) (9, 9)

OR

(0, 0) (7, 0) (3, 0) (9, 0) (6, 0) (2, 0) (8, 0) (4, 0) (4, 5) (8, 5) (6, 5)
(2, 5) (2, 9) (4, 9) (8, 9) (3, 9) (7, 9) (9, 9)

OR

Any other path possible from source to destination
 
Input:

[ 4  4  6  5  5  1  1  1  7  4 ]
[ 3  6  2  4  6  5  7  2  6  6 ]
[ 1  3  6  1  1  1  7  1  4  5 ]
[ 7  5  6  3  1  3  3  1  1  7 ]
[ 3  4  6  4  7  2  6  5  4  4 ]
[ 3  2  5  1  2  5  1  2  3  4 ]
[ 4  2  2  2  5  2  3  7  7  3 ]
[ 7  2  4  3  5  2  2  3  6  3 ]
[ 5  1  4  2  6  4  6  7  3  7 ]
[ 1  4  1  7  5  3  6  5  3  4 ]

Output:

(0, 0) (4, 0) (1, 0) (1, 3) (5, 3) (4, 3) (0, 3) (0, 8) (7, 8) (1, 8) (1, 2)
(3, 2) (9, 2) (8, 2) (4, 2) (4, 8) (8, 8) (5, 8) (2, 8) (6, 8) (6, 1) (4, 1)
(0, 1) (0, 5) (1, 5) (6, 5) (4, 5) (2, 5) (3, 5) (3, 8) (3, 7) (2, 7) (1, 7)
(1, 9) (7, 9) (7, 6) (5, 6) (6, 6) (6, 9) (9, 9)

OR

Any other path possible from source to destination
 
We can use Backtracking to solve this problem. The idea is to start from the source cell in the matrix and explore all four possible paths and recursively check if they will leads to the solution or not. If a path doesn’t reach destination or we have explored all possible routes from the current cell, we backtrack. To make sure that the path is simple and doesn’t contain any cycles, we keep track of cells involved in current path in an matrix and before exploring any cell, we ignore the cell if it is already covered in current path.

We can find all the possible locations we can move to from the given location by using the array that stores the relative position of movement from any location. For example, if the current location is (x, y), we can move to (x + row[k], y + col[k]) for 0 <= k < 4 using below array –


int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };

So, from position (x, y), we can move to: (x – 1, y), (x, y – 1), (x, y + 1) and (x + 1, y).

*/


// N x N matrix
#define N 10

// stores cell cordinates of the matrix
typedef pair<int, int> Node;

// Below arrays details all 4 possible movements from a cell
int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };

// Function to check if it is possible to go to position pt
// from current position. The function returns false if pt is
// not a valid position or it is already visited
bool isValid(vector<Node> path, Node pt)
{
	return (pt.first >= 0) && (pt.first < N) &&
		(pt.second >= 0) && (pt.second < N) &&
		(find(path.begin(), path.end(), pt) == path.end());
}

// Function to print the complete path from source to destination
void printPath(vector<Node> path)
{
	for (Node cell: path)
		cout << "(" << cell.first << ", " << cell.second << ") ";
}

// Find route in a matrix mat from source cell (0, 0) to 
// destination cell (N-1, N-1)
bool findPath(int mat[][N], vector<Node> &path, Node &curr)
{
	// include current vertex in the path
	path.push_back(curr);
	
	// if destination is found, return true
	if (curr.first == N - 1 && curr.second == N - 1)
		return true;
	
	// value of current cell
	int n = mat[curr.first][curr.second];
	
	// check all 4 possible movements from current cell
	// and recurse for each valid movement
	for (int i = 0; i < 4; i++)
	{
		// get next position using value of current cell
		int x = curr.first + row[i] * n;
		int y = curr.second + col[i] * n;

		Node next = make_pair(x, y);

		// check if it is possible to go to position (x, y) 
		// from current position
		if (isValid(path, next) && findPath(mat, path, next))
				return true;
	}
	
	// Backtrack - exclude current vertex in the path
	path.pop_back();
	return false;
}

int main()
{
	int mat[N][N] =
	{
		{ 7, 1, 3, 5, 3, 6, 1, 1, 7, 5 },
		{ 2, 3, 6, 1, 1, 6, 6, 6, 1, 2 },
		{ 6, 1, 7, 2, 1, 4, 7, 6, 6, 2 },
		{ 6, 6, 7, 1, 3, 3, 5, 1, 3, 4 },
		{ 5, 5, 6, 1, 5, 4, 6, 1, 7, 4 },
		{ 3, 5, 5, 2, 7, 5, 3, 4, 3, 6 },
		{ 4, 1, 4, 3, 6, 4, 5, 3, 2, 6 },
		{ 4, 4, 1, 7, 4, 3, 3, 1, 4, 2 },
		{ 4, 4, 5, 1, 5, 2, 3, 5, 3, 5 },
		{ 3, 6, 3, 5, 2, 2, 6, 4, 2, 1 }
	};
	
	vector<Node> path;

	Node source = make_pair(0, 0);
	
	// Find route in a matrix mat from source cell (0, 0) to 
	// destination cell (N-1, N-1)
	if (findPath(mat, path, source))
		printPath(path);
	
	return 0;
}
