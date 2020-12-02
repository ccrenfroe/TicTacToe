// TicTacToe
// By Caleb Renfroe
// Point struct to represent a players move on the TicTacToe board.
#ifndef POINT
#define POINT

struct Point
{
	public:
		int row;
		int col;

		Point(int row, int col);
};

#endif
