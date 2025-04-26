#include "HumanOpponent.h"
#include <iostream>
#include <string>

using namespace std;

HumanOpponent::HumanOpponent(int playerNumber) : GamePlayer(playerNumber) {}

Coordinates HumanOpponent::getMove(GameBoard& board) {
    
    Coordinates coord;
    bool isValidInput = false;

    do {
        cout << "Enter coordinates (A5): ";
        string input;
        cin >> input;

        if (input.length() < 2) {
            cout << "Invalid input. Use format 'A5'." << endl;
            continue;
        }

        char rowChar = toupper(input[0]);
        string colStr = input.substr(1);

        try {
            int col = stoi(colStr);
            coord.row = rowChar - 'A';
            coord.col = col - 1;

            if (coord.row < 0 || coord.row >= board.getNumRows() || col < 1 || col > board.getNumCols()) {
                cout << "This is not a correct move. It is out of the board." << endl;
            } 
            else {
                isValidInput = true;
            }
        } catch (const invalid_argument& e) {
            cout << "Invalid column number." << endl;
        } catch (const out_of_range& e) {
            cout << "Invalid column number out of range." << endl;
        }
    } 
    while (!isValidInput);

    return coord;
}