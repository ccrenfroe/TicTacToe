// TicTacToe
// By Caleb Renfroe
// Game class to represent the logic behind the TicTacToe game. Manages the current state of the game and facilitates the match between the players.

//Includes
#include "game.hpp"

//Constructors
Game::Game(Board& gameboard, Player& player1, Player& player2) : 
	gb{gameboard},
	p1{player1},p2{player2},
	currentState{Gamestate::player1},
	maxMoves{gb.rows * gb.cols},
	currMoves{1}
{}

// Prompts whomevers turn it is and then outputs the gameboard.
void Game::printGame()
{
	std::string currGameState;
	if (this->currentState == Gamestate::player1)
	{
		currGameState = this->p1.getName() + "\'s turn\n";
	}
	else // (this->currentState == Gamestate::player2)
	{
		currGameState = this->p2.getName() + "\'s turn\n";
	}
	std::cout << "================================\n";
	std::cout << currGameState << "\n" << this->gb;
	std::cout << "================================\n";
}


void Game::updateGameState()
{
	char winner = this->gb.checkWinner();
	if(winner == ' ') // AKA no winner.
	{
		// Tie logic.
		if(this->currMoves == this->maxMoves)
		{
			this->currentState = Gamestate::tieGame;
			std::cout << "Tie game!\n";
			exit(0);
		}
		else // swap state to the next player.
		{	
			this->currMoves++;
			if(this->currentState == Gamestate::player1){this->currentState = Gamestate::player2;}
			else{this->currentState = Gamestate::player1;}
		}
	}
	else // Winner logic.
	{
		this->currentState = Gamestate::winner;
		std::cout << winner << "'s win!\n";
		exit(0);
	}
}

// Verifies if a move is within the bounds of the board and not already filled.
bool Game::checkMoveValidity(const Point& sector)
{
	if (sector.row > 0 and sector.row < gb.rows + 1)
	{
		if (sector.col > 0 and sector.col < gb.cols + 1)
		{
			if(gb.sectorFree(sector))
			{
				return true;
			}
		}
	}
	return false;
}

// Takes in a players move on the board. Makes sure that the player adheres to the game boundaries and makes a valid move.
void Game::playerTurn()
{
	Player* currPlayer = NULL;
	
	if (this->currentState == Gamestate::player1){currPlayer = &this->p1;}
	else {currPlayer = &this->p2;}

	Point playerMove = this->makeMove(*currPlayer); // Asking the player to input a move
	while(true)
	{
		// Valid move logic.
		if(this->checkMoveValidity(playerMove))
		{
			this->gb.placePiece(playerMove,*currPlayer);
			break;
		}
		else // Invalid move logic.
		{
			std::cout << "Invalid move. Please enter a valid move.";
			playerMove = this->makeMove(*currPlayer);
		}
	}
}

// Prompt player to input a move and returns the move as a Point.
Point Game::makeMove(const Player& currPlayer) const
{
	int row, col;
	std::cout << currPlayer.getName() << "'s turn.\nPlease enter your move as a row and column choice, seperated by a space. (Ex: 1 2);\n";
	std::cin >> row >> col;
	Point playerMove(row,col);
	return playerMove;
}
