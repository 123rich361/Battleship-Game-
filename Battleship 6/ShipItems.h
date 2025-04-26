#ifndef SHIPITEMS_H
#define SHIPITEMS_H

#include "Ship.h"

// This is a class used to manage a collection of ships items that includes items like to add ships, 
// to fire at a ship, whether the ship is sunk, and whether all the ships have been sunk.
class ShipItems {

private:
    Ship* head; // This a pointer to the first ship in the list.

public:
    ShipItems(); // A constructor to initialize an empty ship collection.
    ~ShipItems(); // This is used as a destructor to deallocate memory used by the ship collection.

    void addShip(char symbol, int size); // Adds a new ship to the collection.

    bool fireAtShip(char symbol); 
    bool isShipSunk(char symbol) const; 
    bool areAllShipsSunk() const; 

    Ship* getShip(char symbol) const; // This gets a ship from the collection based on its symbol.
    int getShipSize(char symbol) const; // This then gets the size of a ship, given the symbol.
};

#endif