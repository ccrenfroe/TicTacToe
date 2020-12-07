// TicTacToe
// By Caleb Renfroe
// Player class to represent one of the players in the TicTacToe match.
#ifndef PLAYER
#define PLAYER

// Includes
#include <string>
#include <iostream>

#include "point.hpp"

class Player
{
	private:
		char symbol;
		std::string name;
	public:
		Player(char symbol, std::string name); // Constructor
		std::string getName() const;
		char getSymbol() const;
};

#endif
