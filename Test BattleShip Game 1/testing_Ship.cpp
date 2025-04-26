#include <iostream>
#include <cassert>
#include "Ship.h"

using namespace std;

void testShipCreation() {
    
    cout << "Testing Ship creation..." << endl;

    Ship ship1 = {'C', 5, 0, true, nullptr};
    
    assert(ship1.symbol == 'C');
    assert(ship1.size == 5);
    assert(ship1.hits == 0);
    assert(ship1.isAfloat == true);
    assert(ship1.next == nullptr);

    Ship ship2 = {'S', 3, 2, false, nullptr}; 
    
    assert(ship2.symbol == 'S');
    assert(ship2.size == 3);
    assert(ship2.hits == 2);
    assert(ship2.isAfloat == false);
    assert(ship2.next == nullptr);

    cout << "Ship creation test passed." << endl;
}