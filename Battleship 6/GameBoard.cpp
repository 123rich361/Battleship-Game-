#include "GameBoard.h"

using namespace std;

// Constructor: Initializes the game board with the given number of rows and columns and sets
// the counts for successful hits and missed shots to 0.
GameBoard::GameBoard(int rows, int cols) : numRows(rows), numCols(cols), successfulHits(0), missedShots(0) {
    
    gridArea = new char*[rows];
    
    for (int i = 0; i < rows; ++i) {
        gridArea[i] = new char[cols];
        
        for (int j = 0; j < cols; ++j) {
            gridArea[i][j] = '-'; // Initialize all cells in the grid to '-' to present it is empty.
        }
    }
}

// Destructor: Deallocates memory used by the game board.
GameBoard::~GameBoard() {
    
    for (int i = 0; i < numRows; ++i) {
        delete[] gridArea[i]; // Deletes each row
    }
    delete[] gridArea; // Deletes the array of rows
    gridArea = nullptr; // Set the pointer to null to prevent dangling pointer
}

// Returns the value at a specific grid location and checks if the provided row and column indices are 
// within bounds.
char GameBoard::getGridValue(int row, int col) const {
    
    if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
        return gridArea[row][col];
    }
    return '\0'; // Return null character for out-of-bounds access
}

// This displays the current state of the board and the ships on the board. The grid is displayed with row and column indices.
// If showShips is true, ships are displayed; otherwise, they are hidden.
void GameBoard::displayBoardState(bool showShips) const {
    
    cout << " ";
    
    for (int i = 1; i <= numCols; ++i) cout << i << " ";
    
    cout << endl;

    for (int i = 0; i < numRows; ++i) {
        
        cout << (char)('A' + i) << " "; // This prints rows (A,B,C,... all the way to J).
        
        for (int j = 0; j < numCols; ++j) {
            char cell = gridArea[i][j];    // This gets the value of the cell in the grid.
            
            if (cell == 'X') {
                cout << "X "; //    This indicates a display hit with "X ".
            } 
            else if (cell == 'O') {
                cout << "O "; // This indicates a display miss hit with "O ".
            } 
            else if (showShips && cell != '-') {
                cout << cell << " "; // Shows the ship symbol if showShips is true
            } 
            else {
                cout << "- "; // Indicates a display empty cell with "- ".
            }
        }
        cout << endl;
    }
}

// This is used to deploy a vessel on the board at a given location and positioning then
// returns true if the vessel was successfully deployed, false otherwise.
bool GameBoard::deployVessel(int row, int col, int size, bool horizontal, char shipSymbol) {
    
    if (!isValidVesselPlacement(row, col, size, horizontal)) return false;

    shipItems.addShip(shipSymbol, size); // Add the ship to the ship collection

    for (int i = 0; i < size; ++i) {
        if (horizontal) {
            gridArea[row][col + i] = shipSymbol; // Place ship horizontally
        } 
        else {
            gridArea[row + i][col] = shipSymbol; // Place ship vertically
        }
    }
    return true;
}

// This is used to simulate firing at a location on the board then
// returns an AttackResult structure containing information about the attack.
AttackResult GameBoard::fireAtLocation(int row, int col, int playerID) {
    
    AttackResult result = {false, false, '\0'}; // This initializes the result structure.

    char& cell = gridArea[row][col];

    if (cell == 'X' || cell == 'O') return result; // Checks if the ship has already been hit or missed

    Move move;
    move.row = row;             // This records the move details.
    move.col = col;
    move.playerID = playerID;
    move.previousValue = cell;

    if (cell != '-') {
        successfulHits++;                    // Increments the hit count, stores the ship symbol, checks if the ship is sunk,
        char shipSymbol = cell;              // and marks the cell as hit on the game board.
        bool sunk = shipItems.fireAtShip(shipSymbol);
        cell = 'X'; // Mark as hit

        result.hit = true;
        result.sunk = sunk;
        result.shipSymbol = shipSymbol;

        moveHistory.push(move);
    } 
    else {                              // Increments missed shots, marks the cell as miss, and 
        missedShots++;                    // stores the record of the move.
        cell = 'O'; 
        moveHistory.push(move);
    }

    return result;
}

// This Checks if all vessels on the board are sunk.
bool GameBoard::areAllVesselsSunk() const {
    
    return shipItems.areAllShipsSunk();
}

// This Undoes the last move made on the board.
void GameBoard::undoLastMove() {
    
    if (!moveHistory.empty()) {
        
        Move lastMove = moveHistory.top(); // Get the last move
        moveHistory.pop(); // Remove the last move from the history
        gridArea[lastMove.row][lastMove.col] = lastMove.previousValue; // Restores the cells previous value

        if (lastMove.previousValue != '-' && lastMove.previousValue != 'O') {

            successfulHits--;
        
        }
        else if (lastMove.previousValue == 'O') {

            missedShots--;
        }
        
        cout << "Move undone at " << (char)('a' + lastMove.row) << (lastMove.col + 1) << endl;
    } 
    else {
        cout << "No moves to undo." << endl;
    }
}

// Checks if the given vessel placement is valid.
bool GameBoard::isValidVesselPlacement(int row, int col, int size, bool horizontal) const {
    
    if (horizontal && (col + size > numCols)) return false; // Check horizontal bounds
    if (!horizontal && (row + size > numRows)) return false; // Check vertical bounds

    for (int i = 0; i < size; ++i) {
        int checkRow = row;
        int checkCol = col;
        
        if (horizontal) checkCol += i;  // Adjust the column for horizontal placement and
        else checkRow += i;            // adjust the row for vertical placement.

        if (gridArea[checkRow][checkCol] != '-') return false; // Cells is occupied
    }
    return true; 
}

// This returns the number of rows in the grid.
int GameBoard::getNumRows() const { return numRows; }

// This returns the number of columns in the grid.
int GameBoard::getNumCols() const { return numCols; }

// This returns the number of successful hits.
int GameBoard::getSuccessfulHits() const { return successfulHits; }

// This returns the number of missed shots.
int GameBoard::getMissedShots() const { return missedShots; }

// This checks if a cell has a ship
bool GameBoard::hasShip(int row, int col) const {
    
    return gridArea[row][col] != '-' && gridArea[row][col] != 'X' && gridArea[row][col] != 'O';
}

// This gets the ship symbol at a cell
char GameBoard::getShipSymbol(int row, int col) const {
    
    return gridArea[row][col];
}