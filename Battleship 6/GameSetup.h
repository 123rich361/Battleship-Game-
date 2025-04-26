#ifndef GAMESETUP_H
#define GAMESETUP_H

// This is a class GameBoard that represents the game board for the Battleship game
class GameBoard;
// This is a class HumanOpponent that represents a human player in the game 
class HumanOpponent;

// This is a function that handles the setup of the player's game board.
void playerBoardSetup(GameBoard& board, HumanOpponent& player);

#endif