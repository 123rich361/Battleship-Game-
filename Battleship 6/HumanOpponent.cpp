#include "HumanOpponent.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor: This sets up the HumanOpponent with the given player number.
HumanOpponent::HumanOpponent(int playerNumber) : GamePlayer(playerNumber) {}

// This function gets the human player's move from user input.
Coordinates HumanOpponent::getMove(GameBoard& board) {
    
    Coordinates coord;
    bool isValidInput = false;

    do {
        cout << "Enter coordinates (A5): "; 
        string input;    // This is used to store the users input
        cin >> input;

        if (input.length() < 2) {    // This is to check if the input is valid 
            
            cout << "Invalid input. Use format 'A5'." << endl;
            continue;   // This continues the loop if the input is invalid
        }

        char rowChar = toupper(input[0]);  // This converts the first character to uppercase
        string colStr = input.substr(1); // This gets the column part of the input 

        try {
            int col = stoi(colStr);
            
            coord.row = rowChar - 'A';
            coord.col = col - 1;
            
            // This checks to see if the coordinates are out of bounds of the board
            if (coord.row < 0 || coord.row >= board.getNumRows() || col < 1 || col > board.getNumCols()) {
                
                cout << "This is not a correct move. It is out of the board." << endl; 
            } 
            else {
                isValidInput = true;  // This sets the input to valid if the coordinates are within bounds of the board
            }
        } catch (const invalid_argument& e) {  // This checks to see if the column is a valid number
            
            cout << "Invalid column number." << endl;
        } catch (const out_of_range& e) {    // This checks to see if the column is out of range
            
            cout << "Invalid column number out of range." << endl;
        }
    } 
    while (!isValidInput);  // This repeats the loop until a valid input is given 

    return coord;
}