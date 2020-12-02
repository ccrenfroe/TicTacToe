// TicTacToe
// By Caleb Renfroe
// Main.

// Includes
#include <iostream>

#include "game.hpp"
#include "point.hpp"

int main()
{
	Board tictactoeBoard;
	Player x('x',"Jill");
	Player o('o',"Bob");
	Game tictactoeGame(tictactoeBoard, x, o); 

	while(true)
	{
		tictactoeGame.playerTurn();
		tictactoeGame.printGame();
		tictactoeGame.updateGameState();
	}
}
