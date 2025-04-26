#include <iostream>

void testAttackResultCreation();
void testCoordinatesCreation();
void testShipCreation();
void testShipItemsAddShip();
void testShipItemsFireAtShip();
void testShipItemsIsShipSunk();
void testShipItemsAreAllShipsSunk();
void testShipItemsGetShip();
void testShipItemsGetShipSize();
void testGameBoardConstructor();
void testGameBoardGetGridValue();
void testGameBoardDeployVessel();
void testGameBoardFireAtLocation();
void testGameBoardAreAllVesselsSunk();
void testGameBoardUndoLastMove();
void testGameBoardDestructor();
void testGameBoardIsValidVesselPlacement();
void testGameBoardGetNumRowsGetNumCols();
void testGameBoardGetSuccessfulHitsGetMissedShots();
void testGameBoardHasShipGetShipSymbol();
void testGamePlayerCreation();
void testHumanOpponentCreation();
void testHumanOpponentGetMove();
void testComputerOpponentCreation();
void testComputerOpponentGetMove();
void testMoveStructure();

using namespace std;

int main() {
    
    cout << "Running tests..." << endl;

    testAttackResultCreation();
    testCoordinatesCreation();
    testShipCreation();
    testShipItemsAddShip();
    testShipItemsFireAtShip();
    testShipItemsIsShipSunk();
    testShipItemsAreAllShipsSunk();
    testShipItemsGetShip();
    testShipItemsGetShipSize();
    testGameBoardConstructor();
    testGameBoardGetGridValue();
    testGameBoardDeployVessel();
    testGameBoardFireAtLocation();
    testGameBoardAreAllVesselsSunk();
    testGameBoardUndoLastMove();
    testGameBoardDestructor();
    testGameBoardIsValidVesselPlacement();
    testGameBoardGetNumRowsGetNumCols();
    testGameBoardGetSuccessfulHitsGetMissedShots();
    testGameBoardHasShipGetShipSymbol();
    testGamePlayerCreation();
    testHumanOpponentCreation();
    testHumanOpponentGetMove();
    testComputerOpponentCreation();
    testComputerOpponentGetMove();
    testMoveStructure();

    cout << "All tests completed." << endl;
    return 0;
}
