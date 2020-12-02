// TicTacToe
// By Caleb Renfroe
// Game class to represent the logic behind the TicTacToe game. Manages the current state of the game and facilitates the match between the players.
#ifndef GAME
#define GAME

// Includes
#include "player.hpp"
#include "board.hpp"

class Game
{
	private:
		Board gb;
		Player p1;
		Player p2;
		enum class Gamestate {player1, player2, tieGame, winner};
		Gamestate currentState;
		// Used to determine when a tie is reached. if currMoves ever equals maxMoves, then that means the board is hfull and there is a tie.
		int maxMoves;
		int currMoves;
	public:
		Game(Board& gameboard, Player& player1, Player& player2);
		void printGame(); // Print out the current state of the game and the board.
		void updateGameState(); // Updates currentState to help manage the game.
		bool checkMoveValidity(const Point& sector);
		void playerTurn();
};

#endif
