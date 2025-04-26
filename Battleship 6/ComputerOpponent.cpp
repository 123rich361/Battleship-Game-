#include "ComputerOpponent.h"
#include "GameBoard.h"
#include <iostream>
#include <random>

using namespace std;

// Constructor for ComputerOpponent: Initializes the given player number and sets the difficulty level.
ComputerOpponent::ComputerOpponent(int playerNumber, string difficulty) : GamePlayer(playerNumber), difficultyLevel(difficulty) {}

// Gets the computer player's next move on the game board.
Coordinates ComputerOpponent::getMove(GameBoard& board) {
    
    Coordinates coord; // Creates a Coordinates variable to hold the coordinates of the move.
    random_device rd; // Creates a random to obtain a seed from the operating system
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> rowDist(0, board.getNumRows() - 1); // Define range for row 
    uniform_int_distribution<> colDist(0, board.getNumCols() - 1); // Define range for column

    coord.row = rowDist(gen); // Generate a random row
    coord.col = colDist(gen); // Generate a random column

    return coord; // Return the random generated coordinates for the computers move
}