#include "GameSetup.h"
#include "GameBoard.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// Function helps to set up the player's game board by allowing the player to place thier ships.
void playerBoardSetup(GameBoard& board, HumanOpponent& player) {
    
    cout << "Place your ships click y to start: ";
    char choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This clears the input buffer

    if (choice == 'y') {
        // This is a list of the ships and their sizes
        vector<pair<char, int>> ships = {
            {'C', 5}, // This is the carrier
            {'B', 4}, // This is the battleship
            {'R', 3}, // This is the cruiser
            {'S', 3}, // This is the submarine
            {'D', 2} // This is the destroyer
        };
        
        // Loop through each ship and ask the player to place it on the board
        for (auto& ship : ships) {
            char shipSymbol = ship.first;
            int shipSize = ship.second;
            int row = 0, col = 0;
            bool horizontal = true;
            bool validPlacement = false;

            while (!validPlacement) {
                
                cout << "Place ship " << shipSymbol << " (size " << shipSize << "). Use 'w' (up), 's' (down), 'a' (left), 'd' (right) to move, Enter to confirm." << endl;
                cout << "Current position: (" << (char)('A' + row) << ", " << col + 1 << ")" << endl;
                
                board.displayBoardState(true); // Shows the ships during the placement

                // Preview the ships placement 
                cout << "Preview: ";
                
                vector<pair<int, int>> previewCoords; // This stores the coordinates of the ships placement 
                bool canPlace = true; //Checks if the ship can be placed 

                for (int j = 0; j < shipSize; ++j) {
                    int previewRow = row;  // This stores the row of the ship placement 
                    int previewCol = col;  // This stores the coulumn of the ship placement 

                    if (horizontal) {    // This is used for the hoizontal placement 
                        previewCol += j;
                    } 
                    else {
                        previewRow += j; // This is used for the vertical placement 
                    }
                    // This checks to see if the ship is out of bounds or occupied
                    if (previewRow < 0 || previewRow >= board.getNumRows() || previewCol < 0 || previewCol >= board.getNumCols()) {
                        
                        cout << " (Out of bounds) ";
                        canPlace = false;
                        break;
                    }

                    if (board.getGridValue(previewRow, previewCol) != '-') {
                        
                        cout << " (Occupied) ";
                        canPlace = false;
                        break;
                    }

                    previewCoords.push_back({previewRow, previewCol});  // This stores the coordinates of the ships placement 
                    
                    cout << (char)('A' + previewRow) << ", " << previewCol + 1 << " "; // This shows the coordinates of the ships placement 
                }

                cout << endl;

                if (!canPlace) {
                    
                    cout << "You cannot place ship here." << endl;
                }
                 // Gets the moves from the user
                string moves;
                
                cout << "Enter your moves (w, a, s, d) or press Enter two times to confirm: ";
                getline(cin, moves);  // This gets the moves from the user

                if (moves.empty()) {
                    // This confirms the placement if Enter is pressed twice
                    char horizontalChar;
                    cout << "Place ship horizontally? (y/n): ";
                    cin >> horizontalChar;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    horizontal = (horizontalChar == 'y');

                    // This checks if the placement is valid before deploying the ship
                    bool isValid = true;
                    
                    for (int j = 0; j < shipSize; ++j) {
                        int checkRow = row;
                        int checkCol = col;
                        
                        if (horizontal) {
                            checkCol += j;
                        } 
                        else {
                            checkRow += j;
                        }
                        // This checks if the ship is out of bounds or occupied
                        if (checkRow < 0 || checkRow >= board.getNumRows() || checkCol < 0 || checkCol >= board.getNumCols() || board.getGridValue(checkRow, checkCol) != '-') {
                            isValid = false;
                            break;
                        }
                    }

                    if (isValid) {   // This is used to deploy the ship if the placement is valid
                        
                        if (board.deployVessel(row, col, shipSize, horizontal, shipSymbol)) {
                            validPlacement = true;
                            // Shows the ship placement on the board
                            
                            cout << "Ship " << shipSymbol << " placed at: ";
                            
                            for (auto& coord : previewCoords) {
                                
                                cout << (char)('A' + coord.first) << coord.second + 1 << " "; // This displays the coordinates of the ship placement 
                            }
                            
                            cout << "(" << shipSymbol << ")" << endl;
                        } 
                        else {
                            cout << "Invalid placement. Try again." << endl;
                        }
                    } 
                    else {
                        cout << "Invalid placement. Try again." << endl;
                    }
                } 
                else {
                    // This updates the ship position based on the moves from the player
                    for (char move : moves) {
                        
                        switch (move) {
                            case 'w': row = max(0, row - 1); break;
                            case 's': row = min(board.getNumRows() - 1, row + 1); break;
                            case 'a': col = max(0, col - 1); break;
                            case 'd': col = min(board.getNumCols() - 1, col + 1); break;
                            default: cout << "Invalid move: " << move << endl; break;
                        }
                    }
                }
            }
        }
    } 
    else {
        // This is used to auto place the ships on the board if the player chooses not to place them manually
        board.deployVessel(0, 0, 5, true, 'C'); // This is the carrier
        board.deployVessel(2, 2, 4, false, 'B'); // This is the battleship
        board.deployVessel(5, 1, 3, true, 'R'); // This is the cruiser
        board.deployVessel(7, 4, 3, false, 'S'); // This is the submarine
        board.deployVessel(9, 0, 2, true, 'D'); // This is the destroyer
    }
}
