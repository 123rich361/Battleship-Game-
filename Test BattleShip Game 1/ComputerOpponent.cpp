#include "ComputerOpponent.h"
#include "GameBoard.h"
#include <iostream>
#include <random>

using namespace std;

ComputerOpponent::ComputerOpponent(int playerNumber, string difficulty) : GamePlayer(playerNumber), difficultyLevel(difficulty) {}

Coordinates ComputerOpponent::getMove(GameBoard& board) {
    
    Coordinates coord;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> rowDist(0, board.getNumRows() - 1);
    uniform_int_distribution<> colDist(0, board.getNumCols() - 1);

    coord.row = rowDist(gen);
    coord.col = colDist(gen);

    return coord;
}