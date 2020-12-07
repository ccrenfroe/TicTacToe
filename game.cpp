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
	if (currentState == Gamestate::player1)
	{
		currGameState = p1.getName() + "\'s turn\n";
	}
	else // (this->currentState == Gamestate::player2)
	{
		currGameState = p2.getName() + "\'s turn\n";
	}
	std::cout << "================================\n";
	std::cout << currGameState << "\n" << gb;
	std::cout << "================================\n";
}


void Game::updateGameState()
{
	char winner = gb.checkWinner();
	if(winner == ' ') // AKA no winner.
	{
		// Tie logic.
		if(currMoves == maxMoves)
		{
			currentState = Gamestate::tieGame;
			std::cout << "Tie game!\n";
			exit(0);
		}
		else // swap state to the next player.
		{	
			currMoves++;
			if(currentState == Gamestate::player1){currentState = Gamestate::player2;}
			else{currentState = Gamestate::player1;}
		}
	}
	else // Winner logic.
	{
		currentState = Gamestate::winner;
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
	
	if (currentState == Gamestate::player1){currPlayer = &p1;}
	else {currPlayer = &p2;}

	Point playerMove = makeMove(*currPlayer); // Asking the player to input a move
	while(true)
	{
		// Valid move logic.
		if(checkMoveValidity(playerMove))
		{
			gb.placePiece(playerMove,*currPlayer);
			break;
		}
		else // Invalid move logic.
		{
			std::cout << "Invalid move. Please enter a valid move.";
			playerMove = makeMove(*currPlayer);
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
