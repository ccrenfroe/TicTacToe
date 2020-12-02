// TicTacToe
// By Caleb Renfroe
// Player class to represent one of the players in the TicTacToe match.

// Includes
#include "player.hpp"

// Constructors
Player::Player(char s, std::string n) :	symbol{s},name{n} {}

// Getters
std::string Player::getName() const{return this->name;}
char Player::getSymbol() const{return this->symbol;}

// Prompt player to input a move and returns the move as a Point.
Point Player::makeMove() const
{
	int row, col;
	std::cout << this->name << "'s turn.\nPlease enter your move as a row and column choice, seperated by a space. (Ex: 1 2);\n";
	std::cin >> row >> col;
	Point playerMove(row,col);
	return playerMove;
}
