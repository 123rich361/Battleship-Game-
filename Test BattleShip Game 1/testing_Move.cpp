#include <iostream>
#include <cassert>
#include "Move.h"

using namespace std;

void testMoveStructure() {
    
    cout << "Testing Move structure..." << endl;

    Move move = {1, 2, 3, 'C'};
    
    assert(move.row == 1);
    assert(move.col == 2);
    assert(move.playerID == 3);
    assert(move.previousValue == 'C');

    cout << "Move structure test passed." << endl;
}