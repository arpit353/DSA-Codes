#include <iostream>
using namespace std;

/*

Check if given set of moves is circular or not. The move is circular if its starting and ending coordinates are the same. The moves can contain instructions to move one unit in same direction (M), to change direction to left of current direction (L) and to change direction to right of current direction (R).

For example,

Set of moves MRMRMRM is circular
Set of moves MRMLMRMRMMRMM is circular


*/

// check if given set of moves is circular on not
bool checkCircularMove(string str)
{
	// start from coordinates (0, 0)
	int x = 0, y = 0;

	// assume initial direction is North
	char dir = 'N';

 	// read each instruction from input string
	for (int i = 0; i < str.length(); i++) 
	{
		switch (str[i]) 
		{
		// move one unit in same direction
		case 'M':
			if (dir == 'N')
				y++;
			else if (dir == 'S')
				y--;
			else if (dir == 'E')
				x++;
			else if (dir == 'W')
				x--;
			break;

		// change direction to left of current direction
		case 'L':
			if (dir == 'N')
				dir = 'W';
			else if (dir == 'W')
				dir = 'S';
			else if (dir == 'S')
				dir = 'E';
			else if (dir == 'E')
				dir = 'N';
			break;

 		// change direction to right of current direction
		case 'R':
			if (dir == 'N')
				dir = 'E';
			else if (dir == 'E')
				dir = 'S';
			else if (dir == 'S')
				dir = 'W';
			 else if (dir == 'W')
				dir = 'N';
		}
	}
	
	// if we're back to starting coordinates (0, 0), 
	// the move is circular 
	return (!x && !y);
}

int main() 
{
	string str = "MMRMMRMMRMM";
	
	if (checkCircularMove(str))
		cout << "Circular Move";
	else
		cout << "Non-Circular Move"; 
	
	return 0;
}