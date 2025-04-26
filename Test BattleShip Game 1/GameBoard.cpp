#include "GameBoard.h"

using namespace std;

GameBoard::GameBoard(int rows, int cols) : numRows(rows), numCols(cols), successfulHits(0), missedShots(0) {
    
    gridArea = new char*[rows];
    
    for (int i = 0; i < rows; ++i) {
        gridArea[i] = new char[cols];
        
        for (int j = 0; j < cols; ++j) {
            gridArea[i][j] = '-';
        }
    }
}

GameBoard::~GameBoard() {
    
    for (int i = 0; i < numRows; ++i) {
        delete[] gridArea[i];
    }
    delete[] gridArea;
    gridArea = nullptr;
}

char GameBoard::getGridValue(int row, int col) const {
    
    if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
        return gridArea[row][col];
    }
    return '\0';
}

void GameBoard::displayBoardState(bool showShips) const {
    
    cout << " ";
    
    for (int i = 1; i <= numCols; ++i) cout << i << " ";
    
    cout << endl;

    for (int i = 0; i < numRows; ++i) {
        cout << (char)('A' + i) << " ";
        for (int j = 0; j < numCols; ++j) {
            char cell = gridArea[i][j];
            if (cell == 'X') {
                cout << "X ";
            } 
            else if (cell == 'O') {
                cout << "O ";
            } 
            else if (showShips && cell != '-') {
                cout << cell << " ";
            } 
            else {
                cout << "- ";
            }
        }
        cout << endl;
    }
}

bool GameBoard::deployVessel(int row, int col, int size, bool horizontal, char shipSymbol) {
    if (!isValidVesselPlacement(row, col, size, horizontal)) return false;

    shipItems.addShip(shipSymbol, size);

    for (int i = 0; i < size; ++i) {
        if (horizontal) {
            gridArea[row][col + i] = shipSymbol;
        } else {
            gridArea[row + i][col] = shipSymbol;
        }
    }
    return true;
}

AttackResult GameBoard::fireAtLocation(int row, int col, int playerID) {
    AttackResult result = {false, false, '\0'};

    char& cell = gridArea[row][col];

    if (cell == 'X' || cell == 'O') return result;

    Move move;
    move.row = row;
    move.col = col;
    move.playerID = playerID;
    move.previousValue = cell;

    if (cell != '-') {
        successfulHits++;
        char shipSymbol = cell;
        bool sunk = shipItems.fireAtShip(shipSymbol);
        cell = 'X';

        result.hit = true;
        result.sunk = sunk;
        result.shipSymbol = shipSymbol;

        moveHistory.push(move);
    } else {
        missedShots++;
        cell = 'O';
        moveHistory.push(move);
    }

    return result;
}

bool GameBoard::areAllVesselsSunk() const {
    return shipItems.areAllShipsSunk();
}

void GameBoard::undoLastMove() {
    if (!moveHistory.empty()) {
        Move lastMove = moveHistory.top();
        moveHistory.pop();
        gridArea[lastMove.row][lastMove.col] = lastMove.previousValue;

        if (lastMove.previousValue != '-' && lastMove.previousValue != 'O') {

            successfulHits--;
        
        }
        else if (lastMove.previousValue == 'O') {

            missedShots--;
        }
        cout << "Move undone at " << (char)('a' + lastMove.row) << (lastMove.col + 1) << endl;
    } else {
        cout << "No moves to undo." << endl;
    }
}

bool GameBoard::isValidVesselPlacement(int row, int col, int size, bool horizontal) const {
    if (horizontal && (col + size > numCols)) return false;
    if (!horizontal && (row + size > numRows)) return false;

    for (int i = 0; i < size; ++i) {
        int checkRow = row;
        int checkCol = col;
        if (horizontal) checkCol += i;
        else checkRow += i;

        if (gridArea[checkRow][checkCol] != '-') return false;
    }
    return true;
}

int GameBoard::getNumRows() const { return numRows; }
int GameBoard::getNumCols() const { return numCols; }
int GameBoard::getSuccessfulHits() const { return successfulHits; }
int GameBoard::getMissedShots() const { return missedShots; }

bool GameBoard::hasShip(int row, int col) const {
    return gridArea[row][col] != '-' && gridArea[row][col] != 'X' && gridArea[row][col] != 'O';
}

char GameBoard::getShipSymbol(int row, int col) const {
    return gridArea[row][col];
}