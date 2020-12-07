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
