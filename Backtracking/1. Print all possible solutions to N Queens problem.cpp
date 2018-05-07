#include <bits/stdc++.h>
using namespace std;

/*
The N queens puzzle is the problem of placing N chess queens on an N × N chessboard so that no two queens threaten each other. Thus, a solution requires that no two queens share the same row, column, or diagonal.
 
For example, for standard 8 × 8 chessboard below is one such configuration –

Q – – – – – – –
– – – – Q – – –
– – – – – – – Q
– – – – – Q – –
– – Q – – – – –
– – – – – – Q –
– Q – – – – – –
– – – Q – – – –

Note that the solution exist for all natural numbers n with the exception of n = 2 and n = 3.


We can solve this problem with the help of backtracking. The idea very simple. We start from the first row and place Queen in each square of the first row and recursively explore remaining rows to check if they leads to the solution or not. If current configuration doesn’t result in a solution, we backtrack. Before exploring any square, we ignore the square if two queens threaten each other.

*/


// N x N chessboard
#define N 8

// Function to check if two queens threaten each other or not
bool isSafe(char mat[][N], int r, int c)
{
	// return false if two queens share the same column
	for (int i = 0; i < r; i++)
		if (mat[i][c] == 'Q')
			return false;

	// return false if two queens share the same \ diagonal
	for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
		if (mat[i][j] == 'Q')
			return false;

	// return false if two queens share the same / diagonal
	for (int i = r, j = c; i >= 0 && j < N; i--, j++)
		if (mat[i][j] == 'Q')
			return false;

	return true;
}

void nQueen(char mat[][N], int r, int c)
{
	// if N queens are placed successfully, print the solution
	if (c == 0 && r == N) 
	{
		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < N; j++)
				cout << mat[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		
		return;
	}

	// place Queen at every square in current row r
	// and recurse for each valid movement	
	for (int i = 0; i < N; i++) 
	{
		// if no two queens threaten each other
		if (isSafe(mat, r, i)) 
		{
			// place queen on current square
			mat[r][i] = 'Q';

			// recurse for next row
			nQueen(mat, r + 1, 0);

			// backtrack and remove queen from current square
			mat[r][i] = '-';
		}
	}
}

int main()
{
	// mat[][] keeps track of position of Queens in current configuration
	char mat[N][N];

	// initalize mat[][] by '-'
	memset(mat, '-', sizeof mat);

	nQueen(mat, 0, 0);

	return 0;
}
