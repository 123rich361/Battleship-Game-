#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GameBoard.h"
#include "GamePlayer.h"
#include "HumanOpponent.h"
#include "ComputerOpponent.h"
#include "GameSetup.h"

using namespace std;

int main() {
    
    srand(time(0)); // This seeds the random number generator for the computers moves

    // This is the instruction manual used to help the player understand how to play the game
    // and the keys to press to play the game.
    cout << "Welcome to Battleship!" << endl;
    cout << "-----------------------" << endl;
    cout << "Instructions:" << endl;
    cout << "1. Enter the board size (rows and columns)." << endl;
    cout << "2. Choose to place your ships manually or let the computer auto-place them." << endl;
    cout << " - If placing manually, use 'w' (up), 's' (down), 'a' (left), 'd' (right) to position the ship, and Spacebar to confirm." << endl;
    cout << " - Enter 'y' for horizontal placement or 'n' for vertical placement." << endl;
    cout << "3. Take turns with the computer to fire at each other's ships." << endl;
    cout << " - Enter coordinates in the format 'A5' (letter for row, number for column)." << endl;
    cout << "4. The first player to sink all of the opponent's ships wins!" << endl;
    cout << "-----------------------" << endl;
    cout << "Keys to Press:" << endl;
    cout << " - w: Move ship up" << endl;
    cout << " - s: Move ship down" << endl;
    cout << " - a: Move ship left" << endl;
    cout << " - d: Move ship right" << endl;
    cout << " - Spacebar: Confirm ship placement" << endl;
    cout << " - y: Yes (for horizontal placement)" << endl;
    cout << " - n: No (for vertical placement)" << endl;
    cout << " - u: Undo Last move" << endl;
    cout << "-----------------------" << endl;

    int rows = 10, cols = 10; // Sets the default board size to 10x10
    cout << "Enter board size (rows cols): "; // Used to get the board size from the user player
    cin >> rows >> cols;

    GameBoard playerBoard(rows, cols); // This creates the player's board 
    GameBoard computerBoard(rows, cols); // This creates the computer's board

    HumanOpponent player1(1); // This creates the human player
    ComputerOpponent player2(2, "easy"); // This creates the computer player

    playerBoardSetup(playerBoard, player1); // Sets up the player's board

    // This is used to auto place the ships in the computers board
    computerBoard.deployVessel(0, 0, 5, true, 'C'); // This is the carrier
    computerBoard.deployVessel(2, 2, 4, false, 'B'); // This is the battleship
    computerBoard.deployVessel(5, 1, 3, true, 'R'); // This is the cruiser
    computerBoard.deployVessel(7, 4, 3, false, 'S'); // This is the submarine
    computerBoard.deployVessel(9, 0, 2, true, 'D'); // This is the destroyer

    bool gameOver = false; // This is used to check if the game is over
    int turn = 1;   // Used to keep track of the turns in the game

    while (!gameOver) {      // Used to loop the game until it is over
        
        cout << "Turn " << turn++ << endl; // This shows the current turn of the game

        // This is used to show the boards of the players and the computer
        cout << "Player's Turn:" << endl;
        cout << "Your Board:" << endl;
        playerBoard.displayBoardState(true); // Shows the ships on the player's board
        cout << "Computer's Board:" << endl;
        computerBoard.displayBoardState(false);  // Shows the ships on the computers board

        Coordinates playerMove = player1.getMove(computerBoard); // This gets the player's move
        AttackResult attackResult = computerBoard.fireAtLocation(playerMove.row, playerMove.col, player1.getPlayerID()); // This processes the players move 
           
        if (attackResult.hit) {      // This checks to see if the player hit a ship
            
            if (attackResult.sunk) {  // This checks to see if the ship was sunk 
                cout << "Hit! You sank the computer's " << attackResult.shipSymbol << "!" << endl;
                
                if (computerBoard.areAllVesselsSunk()) {  // This checks to see if all ships are sunk
                    cout << "Player 1 wins!" << endl;
                    gameOver = true;
                }
            } 
            else {
                cout << "Hit!" << endl;
            }
        } 
        else {
            cout << "Miss!" << endl;
        }

        if (gameOver) break;  // This checks to see if the game is over 

        // This is used to show the boards of the players and and the computer after the players turn
        cout << "Computer's Turn:" << endl;
        cout << "Your Board:" << endl;
        playerBoard.displayBoardState(true); // This shows the ships and the hits and misses on the players board 
        cout << "Computer's Board:" << endl;
        computerBoard.displayBoardState(false);    // This shows the ships and the hits and misses on the computers board 

        Coordinates computerMove = player2.getMove(playerBoard); // This gets the computers move 
        cout << "Computer attacks " << (char)('A' + computerMove.row) << (computerMove.col + 1) << endl; // This shows the coordinates of the computers move 
        AttackResult computerHitResult = playerBoard.fireAtLocation(computerMove.row, computerMove.col, player2.getPlayerID()); // This processes the computers move 

        if (computerHitResult.hit) {    // This checks to see if the computer hit a ship 
            
            if (computerHitResult.sunk) {   // This checks to see if the ship was sunk 
                cout << "Computer hit and sank your " << computerHitResult.shipSymbol << "!" << endl;
                cout << "Computer wins!" << endl;
                gameOver = true;
            } 
            else {
                cout << "Computer hits!" << endl;
            }
        } 
        else {
            cout << "Computer misses!" << endl;
        }
    }

    cout << "Game Over!" << endl;
    return 0;
}
