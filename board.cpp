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
	board[sector.row - 1][sector.col - 1] = player.getSymbol();
}

// Checks if a sector is free to confirm if a players sector input is valid.
bool Board::sectorFree(const Point& sector)
{
	if(board[sector.row - 1][sector.col - 1] == ' '){return true;}
	return false;
}

// Determines if their is a winner or not. Returns ' ' if their is no winner, otherwise it returns the symbol of whomever has a winning 3 in a row.
char Board::checkWinner()
{
	// Check verticals.
	for(int i=0; i < rows; i++)
	{
		if(board[i][0] == board[i][1] and 
		   board[i][1] == board[i][2] and 
		   board[i][0] != ' ')
		{return this->board[i][0];}
	}
	// Check horizontals.
	for(int i=0; i < this->cols; i++)
	{
		if(board[0][i] == board[1][i] and
		   board[1][i] == board[2][i] and
		   board[0][i] != ' ')
		{return board[0][i];}
	}
	// Check diagonals.
	if(board[0][0] == board[1][1] and
	   board[1][1] == board[2][2] and
	   board[0][0] !=' ')
	{return board[0][0];}
	if(board[2][0] == board[1][1] and
	   board[1][1] == board[0][2] and 
	   board[2][0] !=' ')
	{return board[2][0];}
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
