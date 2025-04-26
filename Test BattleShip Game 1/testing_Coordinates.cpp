#include <iostream>
#include <cassert>
#include "Coordinates.h"

using namespace std;

void testCoordinatesCreation() {
    
    cout << "Testing Coordinates creation..." << endl;

    Coordinates coord1 = {5, 7};
    assert(coord1.row == 5);
    assert(coord1.col == 7);

    Coordinates coord2 = {0, 0};
    assert(coord2.row == 0);
    assert(coord2.col == 0);

    Coordinates coord3 = {-1, 100}; 
    assert(coord3.row == -1);
    assert(coord3.col == 100);

    cout << "Coordinates creation test passed." << endl;
}