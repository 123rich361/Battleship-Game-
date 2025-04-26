#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <stack>
#include "Coordinates.h"
#include "ShipItems.h"
#include "Move.h"
#include "AttackResult.h"

using namespace std;

class GameBoard {

private:
    char** gridArea;
    int numRows;
    int numCols;
    ShipItems shipItems;
    int successfulHits;
    int missedShots;
    stack<Move> moveHistory;

public:
    GameBoard(int rows, int cols);
    ~GameBoard();
    bool isValidVesselPlacement(int row, int col, int size, bool horizontal) const;
    void displayBoardState(bool showShips = false) const;
    bool deployVessel(int row, int col, int size, bool horizontal, char shipSymbol);
    AttackResult fireAtLocation(int row, int col, int playerID);
    bool areAllVesselsSunk() const;
    void undoLastMove();
    int getNumRows() const;
    int getNumCols() const;
    int getSuccessfulHits() const;
    int getMissedShots() const;
    char getGridValue(int row, int col) const;
    bool hasShip(int row, int col) const;
    char getShipSymbol(int row, int col) const;
};

#endif