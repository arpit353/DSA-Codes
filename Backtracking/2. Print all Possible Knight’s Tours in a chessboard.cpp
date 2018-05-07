#include <bits/stdc++.h>
using namespace std;
 
/*
Given a chess board, print all sequences of moves of a knight on a chessboard such that the knight visits every square only once.

For example, for standard 8 × 8 chessboard below is one such tour. We have started the tour from top-leftmost of the board (marked as 1) and consecutive moves of the knight are represented by the next number.

 1 50 45 62 31 18  9 64
46 61 32 49 10 63 30 17
51  2 47 44 33 28 19  8
60 35 42 27 48 11 16 29
41 52  3 34 43 24  7 20
36 59 38 55 26 21 12 15
53 40 57  4 23 14 25  6
58 37 54 39 56  5 22 13

The Knight should search for a path from the starting position until it visits every square or until it exhausts all possibilities. We can easily achieve this with the help of backtracking. We start from given source square in the chessboard and recursively explore all eight paths possible to check if they leads to the solution or not. If current path doesn’t reach destination or we have explored all possible routes from the current square, we backtrack. To make sure that the path is simple and doesn’t contain any cycles, we keep track of squares involved in current path in an chessboard and before exploring any square, we ignore the square if it is already covered in current path.

We can find all the possible locations the Knight can move to from the given location by using the array that stores the relative position of Knight movement from any location. For example, if the current location is (x, y), we can move to (x + row[k], y + col[k]) for 0 <= k <=7 using below array. 
row[] = [ 2, 1, -1, -2, -2, -1, 1, 2, 2 ]
col[] = [ 1, 2, 2, 1, -1, -2, -2, -1, 1 ]

So, from a position (x, y) in the chessboard, the valid moves are:

(x + 2, y + 1)
(x + 1, y + 2)
(x – 1, y + 2)
(x – 2, y + 1)
(x – 2, y – 1)
(x – 1, y – 2)
(x + 1, y – 2)
(x + 2, y – 1)

*/


// N x N chessboard
#define N 5
 
// Below arrays details all 8 possible movements for a knight. 
// It is important to avoid changing sequence of below arrays
int row[] = { 2, 1, -1, -2, -2, -1,  1,  2 , 2 };
int col[] = { 1, 2,  2,  1, -1, -2, -2, -1, 1 };
 
// Check if (x, y) is valid chess board cordinates
// Note that a knight cannot go out of the chessboard
bool isValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N)
        return false;
  
    return true;
}
 
// Recursive function to perform the Knight's tour using backtracking
void KnightTour(int visited[N][N], int x, int y, int pos)
{
    // mark current square as visited   
    visited[x][y] = pos;
     
    // if all squares are visited, print the solution
    if (pos >= N*N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << visited[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        // backtrack before returning
        visited[x][y] = 0;
        return;
    }
 
    // check for all 8 possible movements for a knight
    // and recurse for each valid movement
    for (int k = 0; k < 8; k++)
    {
        // Get the new position of Knight from current
        // position on chessboard
        int newX = x + row[k];
        int newY = y + col[k];
 
        // if new position is a valid and not visited yet
        if (isValid(newX, newY) && !visited[newX][newY])
            KnightTour(visited, newX, newY, pos + 1);
    }
 
    // backtrack from current square and remove it from current path
    visited[x][y] = 0;
}
 
int main()
{
    // visited[][] serves two purpose -
    // 1. It keep track of squares involved the Knight's tour. 
    // 2. It stores the order in which the squares are visited
    int visited[N][N];
     
    // initalize visited[][] by 0 (unvisited)
    memset(visited, 0, sizeof visited);
 
    int pos = 1;
     
    // start knight tour from corner square (0, 0)
    KnightTour(visited, 0, 0, pos);
     
    return 0;
}
