#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <stack>
#include "Coordinates.h"
#include "ShipItems.h"
#include "Move.h"
#include "AttackResult.h"

using namespace std;

// This is a class that represents the game board for the Battleship game and the variables are used to
// indicate the grid area of the game board, the ships, and the number of rows and columns in the grid.
class GameBoard {

private:
    char** gridArea; // This is a 2D array representing the game board grid.
    int numRows; // The number of rows in the grid.
    int numCols; // The number of columns in the grid.
    ShipItems shipItems; // The collection of ships deployed on the board.
    int successfulHits; // The number of successful hits made on the board.
    int missedShots; // The number of missed shots on the board.
    stack<Move> moveHistory; // Stack is used to store the history of moves for undo functionality.

    bool isValidVesselPlacement(int row, int col, int size, bool horizontal) const; // Helper function to check if a vessel can be placed at the given location.

public:
    GameBoard(int rows, int cols); // This constructor is used to initialize the game board with the specified number of rows and columns.
    ~GameBoard(); // Destructor to deallocate memory used by the game board.

    void displayBoardState(bool showShips = false) const; // Displays the current state of the board.

    bool deployVessel(int row, int col, int size, bool horizontal, char shipSymbol); // This deploys a vessel on the board.
    AttackResult fireAtLocation(int row, int col, int playerID); // Then simulates firing at a location on the board.
    bool areAllVesselsSunk() const; // Then checks if all vessels on the board are sunk.

    void undoLastMove(); // Undoes the last move made on the board.

    int getNumRows() const; // Gets the number of rows in the grid.
    int getNumCols() const; // Then gets the number of columns in the grid.
    int getSuccessfulHits() const; // Then gets the number of successful hits.
    int getMissedShots() const; // Then gets the number of missed shots.
    char getGridValue(int row, int col) const; // Then gets the value at a specific grid location.

    bool hasShip(int row, int col) const; // Checks if a cell has a ship
    char getShipSymbol(int row, int col) const; // Gets the ship symbol at a cell
};

#endif