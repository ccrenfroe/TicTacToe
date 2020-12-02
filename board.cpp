// TicTacToe
// By Caleb Renfroe
// Board class to represent the TicTacToe board that the game is played on.

// Includes
#include "board.hpp"

// Constructors
Board::Board() : board{{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}},rows{(int) board.size()},cols{(int) board[0].size()}
{}

// Places the players symbol onto the board at a specified sector. row and col are subtracted by 1 to account for the 0th index.
void Board::placePiece(const Point& sector, const Player& player)
{
	this->board[sector.row - 1][sector.col - 1] = player.getSymbol();
}

// Checks if a sector is free to confirm if a players sector input is valid.
bool Board::sectorFree(const Point& sector)
{
	if(this->board[sector.row - 1][sector.col - 1] == ' '){return true;}
	return false;
}

// Determines if their is a winner or not. Returns ' ' if their is no winner, otherwise it returns the symbol of whomever has a winning 3 in a row.
char Board::checkWinner()
{
	// Check verticals.
	for(int i=0; i < this->rows; i++)
	{
		if(this->board[i][0] == this->board[i][1] and 
		   this->board[i][1] == this->board[i][2] and 
		   this->board[i][0] != ' ')
		{return this->board[i][0];}
	}
	// Check horizontals.
	for(int i=0; i < this->cols; i++)
	{
		if(this->board[0][i] == this->board[1][i] and
		   this->board[1][i] == this->board[2][i] and
		   this->board[0][i] != ' ')
		{return this->board[0][i];}
	}
	// Check diagonals.
	if(this->board[0][0] == this->board[1][1] and
	   this->board[1][1] == this->board[2][2] and
	   this->board[0][0] !=' ')
	{return this->board[0][0];}
	if(this->board[2][0] == this->board[1][1] and
	   this->board[1][1] == this->board[0][2] and 
	   this->board[2][0] !=' ')
	{return this->board[2][0];}
	return ' '; // AKA no winner.
}

std::ostream& operator<<(std::ostream& strm, const Board& b)
{
	// Prints out the board with brackets around each sector to prettify it.
	for(int i = 0; i < b.board.size(); i++)
	{
		for(int j = 0; j < b.board[0].size(); j++)
		{
			strm << "[" << b.board[i][j] << "]";
		}
		strm << "\n";
	}
	return strm;
}
