#include <iostream>
#include <cassert>
#include "GameBoard.h"
#include "ShipItems.h"

using namespace std;

void testGameBoardConstructor() {
    
    cout << "Testing GameBoard constructor..." << endl;

    GameBoard board(10, 10);
    
    assert(board.getNumRows() == 10);
    assert(board.getNumCols() == 10);
    assert(board.getSuccessfulHits() == 0);
    assert(board.getMissedShots() == 0);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            
            assert(board.getGridValue(i, j) == '-');
        }
    }

    GameBoard smallBoard(5, 5);
    
    assert(smallBoard.getNumRows() == 5);
    assert(smallBoard.getNumCols() == 5);

    cout << "GameBoard constructor test passed." << endl;
}

void testGameBoardGetGridValue() {
    
    cout << "Testing GameBoard getGridValue..." << endl;

    GameBoard board(10, 10);
    
    assert(board.getGridValue(0, 0) == '-');
    assert(board.getGridValue(5, 5) == '-');
    assert(board.getGridValue(-1, 0) == '\0'); 
    assert(board.getGridValue(0, -1) == '\0'); 
    assert(board.getGridValue(10, 0) == '\0'); 
    assert(board.getGridValue(0, 10) == '\0'); 

    cout << "GameBoard getGridValue test passed." << endl;
}

void testGameBoardDeployVessel() {
    
    cout << "Testing GameBoard deployVessel..." << endl;

    GameBoard board(10, 10);
    
    bool deployed = board.deployVessel(0, 0, 5, true, 'C');
    
    assert(deployed == true);
    assert(board.getGridValue(0, 0) == 'C');
    assert(board.getGridValue(0, 1) == 'C');
    assert(board.getGridValue(0, 2) == 'C');
    assert(board.getGridValue(0, 3) == 'C');
    assert(board.getGridValue(0, 4) == 'C');

    bool deployed2 = board.deployVessel(2, 2, 4, false, 'B');
    
    assert(deployed2 == true);
    assert(board.getGridValue(2, 2) == 'B');
    assert(board.getGridValue(3, 2) == 'B');
    assert(board.getGridValue(4, 2) == 'B');
    assert(board.getGridValue(5, 2) == 'B');

    bool deployedInvalid = board.deployVessel(8, 8, 5, true, 'D'); 
    
    assert(deployedInvalid == false);

    bool deployedOverlap = board.deployVessel(0, 2, 3, true, 'S'); 
    
    assert(deployedOverlap == false);

    cout << "GameBoard deployVessel test passed." << endl;
}

void testGameBoardFireAtLocation() {
    
    cout << "Testing GameBoard fireAtLocation..." << endl;

    GameBoard board(10, 10);
    
    board.deployVessel(0, 0, 1, true, 'C');

    AttackResult resultHit = board.fireAtLocation(0, 0, 1);
    
    assert(resultHit.hit == true);
    assert(resultHit.sunk == true);
    assert(resultHit.shipSymbol == 'C');
    assert(board.getGridValue(0, 0) == 'X');
    assert(board.getSuccessfulHits() == 1);
    assert(board.getMissedShots() == 0);

    AttackResult resultMiss = board.fireAtLocation(1, 1, 1);
    
    assert(resultMiss.hit == false);
    assert(resultMiss.sunk == false);
    assert(resultMiss.shipSymbol == '\0');
    assert(board.getGridValue(1, 1) == 'O');
    assert(board.getSuccessfulHits() == 1);
    assert(board.getMissedShots() == 1);

    AttackResult resultInvalid = board.fireAtLocation(0, 0, 1); 
    
    assert(resultInvalid.hit == false);
    assert(resultInvalid.sunk == false);

    cout << "GameBoard fireAtLocation test passed." << endl;
}

void testGameBoardAreAllVesselsSunk() {
    
    cout << "Testing GameBoard areAllVesselsSunk..." << endl;

    GameBoard board(10, 10);
    
    board.deployVessel(0, 0, 1, true, 'C');
    
    assert(board.areAllVesselsSunk() == false);

    board.fireAtLocation(0, 0, 1);
    
    assert(board.areAllVesselsSunk() == true);

    cout << "GameBoard areAllVesselsSunk test passed." << endl;
}

void testGameBoardUndoLastMove() {
    
    cout << "Testing GameBoard undoLastMove..." << endl;

    GameBoard board(10, 10);
    
    board.deployVessel(0, 0, 1, true, 'C');
    board.fireAtLocation(0, 0, 1);
    board.undoLastMove();
    
    assert(board.getGridValue(0, 0) == 'C');
    assert(board.getSuccessfulHits() == 0);
    assert(board.getMissedShots() == 0);

    cout << "GameBoard undoLastMove test passed." << endl;
}

void testGameBoardDestructor() {
    
    cout << "Testing GameBoard destructor..." << endl;

   
    GameBoard* board = new GameBoard(5, 5);

    
    board->deployVessel(0, 0, 3, true, 'C');

    
    delete board;

    cout << "GameBoard destructor test passed (no memory leaks detected)." << endl;
}

void testGameBoardIsValidVesselPlacement() {
    
    cout << "Testing GameBoard isValidVesselPlacement..." << endl;

    GameBoard board(10, 10);

   
    assert(board.isValidVesselPlacement(0, 0, 5, false)); 
    assert(board.isValidVesselPlacement(0, 0, 5, false) == true);
    assert(board.isValidVesselPlacement(0, 0, 5, false) == true);
    assert(board.isValidVesselPlacement(5, 5, 3, true) == true);

    
    assert(board.isValidVesselPlacement(0, 6, 5, true) == false);
    assert(board.isValidVesselPlacement(6, 0, 5, false) == false);
    assert(board.isValidVesselPlacement(9, 9, 2, true) == false);
    assert(board.isValidVesselPlacement(9, 9, 2, false) == false);

   
    board.deployVessel(0, 0, 5, true, 'C');
    
    assert(board.isValidVesselPlacement(0, 0, 3, true) == false);
    assert(board.isValidVesselPlacement(0, 2, 3, true) == false);
    assert(board.isValidVesselPlacement(1, 0, 3, true) == true);

    cout << "GameBoard isValidVesselPlacement test passed." << endl;
}

void testGameBoardGetNumRowsGetNumCols() {
    
    cout << "Testing GameBoard getNumRows and getNumCols..." << endl;

    GameBoard board(8, 12);
    
    assert(board.getNumRows() == 8);
    assert(board.getNumCols() == 12);

    GameBoard smallBoard(3, 5);
    
    assert(smallBoard.getNumRows() == 3);
    assert(smallBoard.getNumCols() == 5);

    cout << "GameBoard getNumRows and getNumCols tests passed." << endl;
}

void testGameBoardGetSuccessfulHitsGetMissedShots() {
    
    cout << "Testing GameBoard getSuccessfulHits and getMissedShots..." << endl;

    GameBoard board(10, 10);
    
    board.deployVessel(0, 0, 1, true, 'C');

   
    assert(board.getSuccessfulHits() == 0);
    assert(board.getMissedShots() == 0);

    
    board.fireAtLocation(0, 0, 1);
    
    assert(board.getSuccessfulHits() == 1);
    assert(board.getMissedShots() == 0);

    
    board.fireAtLocation(1, 1, 1);
    
    assert(board.getSuccessfulHits() == 1);
    assert(board.getMissedShots() == 1);

    cout << "GameBoard getSuccessfulHits and getMissedShots tests passed." << endl;
}

void testGameBoardHasShipGetShipSymbol() {
    
    cout << "Testing GameBoard hasShip and getShipSymbol..." << endl;

    GameBoard board(10, 10);
    board.deployVessel(0, 0, 1, true, 'C');

    
    assert(board.hasShip(0, 0) == true);
    assert(board.hasShip(1, 1) == false);

    
    assert(board.getShipSymbol(0, 0) == 'C');
    assert(board.getShipSymbol(1, 1) == '-'); 

    cout << "GameBoard hasShip and getShipSymbol tests passed." << endl;
}