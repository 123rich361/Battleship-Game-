#include <iostream>
#include <cassert>
#include "ShipItems.h"
#include "Ship.h"

using namespace std;

void testShipItemsAddShip() {
    
    cout << "Testing ShipItems addShip..." << endl;

    ShipItems shipItems;
    shipItems.addShip('C', 5);
    Ship* ship = shipItems.getShip('C');
    
    assert(ship != nullptr);
    assert(ship->symbol == 'C');
    assert(ship->size == 5);
    assert(ship->isAfloat == true);

    shipItems.addShip('B', 4);
    Ship* shipB = shipItems.getShip('B');
    
    assert(shipB != nullptr);
    assert(shipB->symbol == 'B');
    assert(shipB->size == 4);
    assert(shipB->isAfloat == true);
    assert(shipB->next == ship); 

    cout << "ShipItems addShip test passed." << endl;
}

void testShipItemsFireAtShip() {
    
    cout << "Testing ShipItems fireAtShip..." << endl;

    ShipItems shipItems;
    shipItems.addShip('C', 5);
    
    bool hit = shipItems.fireAtShip('C');
    
    assert(hit == true);
    Ship* ship = shipItems.getShip('C');
    
    assert(ship->hits == 1);

    shipItems.fireAtShip('C');
    shipItems.fireAtShip('C');
    shipItems.fireAtShip('C');
    shipItems.fireAtShip('C');
    
    assert(shipItems.isShipSunk('C') == true);

    bool hitAgain = shipItems.fireAtShip('C'); 
    
    assert(hitAgain == false);

    cout << "ShipItems fireAtShip test passed." << endl;
}

void testShipItemsIsShipSunk() {
    
    cout << "Testing ShipItems isShipSunk..." << endl;

    ShipItems shipItems;
    shipItems.addShip('C', 5);
    
    assert(shipItems.isShipSunk('C') == false);

    shipItems.fireAtShip('C');
    shipItems.fireAtShip('C');
    shipItems.fireAtShip('C');
    shipItems.fireAtShip('C');
    shipItems.fireAtShip('C');
    
    assert(shipItems.isShipSunk('C') == true);

    assert(shipItems.isShipSunk('X') == true); 

    cout << "ShipItems isShipSunk test passed." << endl;
}

void testShipItemsAreAllShipsSunk() {
    
    cout << "Testing ShipItems areAllShipsSunk..." << endl;

    ShipItems shipItems;
    shipItems.addShip('C', 5);
    shipItems.addShip('B', 4);
    
    assert(shipItems.areAllShipsSunk() == false);

    shipItems.fireAtShip('C');
    shipItems.fireAtShip('C');
    shipItems.fireAtShip('C');
    shipItems.fireAtShip('C');
    shipItems.fireAtShip('C');
    
    assert(shipItems.areAllShipsSunk() == false); 

    shipItems.fireAtShip('B');
    shipItems.fireAtShip('B');
    shipItems.fireAtShip('B');
    shipItems.fireAtShip('B');
    
    assert(shipItems.areAllShipsSunk() == true);

    cout << "ShipItems areAllShipsSunk test passed." << endl;
}

void testShipItemsGetShip() {
    
    cout << "Testing ShipItems getShip..." << endl;

    ShipItems shipItems;
    shipItems.addShip('C', 5);
    Ship* ship = shipItems.getShip('C');
    (ship != nullptr);
    
    assert(ship->symbol == 'C');

    Ship* ship2 = shipItems.getShip('X');
    
    assert(ship2 == nullptr);

    cout << "ShipItems getShip test passed." << endl;
}

void testShipItemsGetShipSize() {
    
    cout << "Testing ShipItems getShipSize..." << endl;

    ShipItems shipItems;
    shipItems.addShip('C', 5);
    
    assert(shipItems.getShipSize('C') == 5);
    assert(shipItems.getShipSize('X') == 0);

    cout << "ShipItems getShipSize test passed." << endl;
}