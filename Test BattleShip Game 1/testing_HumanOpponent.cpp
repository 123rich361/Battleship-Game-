#include <iostream>
#include <cassert>
#include "HumanOpponent.h"
#include "GameBoard.h"
#include "Coordinates.h"

using namespace std;

void testHumanOpponentCreation() {
    
    cout << "Testing HumanOpponent creation..." << endl;

    HumanOpponent player(1);
    
    assert(player.getPlayerID() == 1);

    cout << "HumanOpponent creation test passed." << endl;
}

void testHumanOpponentGetMove() {
    
    cout << "Testing HumanOpponent getMove (basic)..." << endl;

    HumanOpponent player(1);
    GameBoard board(5, 5);

    cout << "HumanOpponent getMove test passed (basic)." << endl;
}