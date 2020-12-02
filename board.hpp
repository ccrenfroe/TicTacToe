// TicTacToe
// By Caleb Renfroe
// Board class to represent the TicTacToe board that the game is played on.
#ifndef BOARD
#define BOARD

// Includes
#include <iostream>
#include <array>

#include "player.hpp"
#include "point.hpp"

class Board
{
	private:
		std::array<std::array<char,3>,3> board;
		friend std::ostream& operator<<(std::ostream& strm, const Board& b);
	public:
		// Rows and Columns made public as they are not sensitive variables. Used in functions where looping over the board is needed.
		int rows;
		int cols;
		Board();
		void placePiece(const Point& sector, const Player& player);
		bool sectorFree(const Point& sector);
		char checkWinner();
};

#endif
