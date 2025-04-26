#include <iostream>
#include <cassert>
#include "ComputerOpponent.h"
#include "GameBoard.h"
#include "Coordinates.h"

using namespace std;

void testComputerOpponentCreation() {
    
    cout << "Testing ComputerOpponent creation..." << endl;

    ComputerOpponent computer(2, "easy");
    assert(computer.getPlayerID() == 2);

    cout << "ComputerOpponent creation test passed." << endl;
}

void testComputerOpponentGetMove() {
    
    cout << "Testing ComputerOpponent getMove..." << endl;

    ComputerOpponent computer(2, "easy");
    GameBoard board(10, 10);
    Coordinates move = computer.getMove(board);
    assert(move.row >= 0 && move.row < 10);
    assert(move.col >= 0 && move.col < 10);

    cout << "ComputerOpponent getMove test passed." << endl;
}