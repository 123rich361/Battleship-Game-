#include "ShipItems.h"

// The ShipItems() is a constructor: of ShipItems and initializes an empty ShipItems.
ShipItems::ShipItems() : head(nullptr) {}

// The ~ShipItems() is a destructor: of ShipItems and deallocates memory for all the ships in the collection to prevent memory leaks.
ShipItems::~ShipItems() {
    
    Ship* current = head;
    
    while (current != nullptr) {
        Ship* next = current->next;    // The arrow operator is used to access members in this case it stores the next ship
        delete current;
        current = next;
    }
    head = nullptr; // Reset head after deleting all nodes and avoids dangling pointers.
}

// This is used to add a new ship to the ShipItems.
void ShipItems::addShip(char symbol, int size) {
    
    Ship* newShip = new Ship;
    newShip->symbol = symbol;           // Sets the new ship symbol
    newShip->size = size;               // Then sets the new ship size 
    newShip->hits = 0;                  // Then sets the value of hit to 0
    newShip->isAfloat = true;           //Then checks if a ship is still afloat
    newShip->next = head;               // This inserts the new ship at the beginning of the list
    head = newShip;                     // This adds head to the new ship.
}

// Used to simulate firing at a ship identified by its symbol then checks if the ship is afloat then
// returns true if the ship was hit (and potentially sunk), false otherwise.
bool ShipItems::fireAtShip(char symbol) {
    
    Ship* ship = getShip(symbol);
    
    if (ship && ship->isAfloat) {
        ship->hits++;
        
        if (ship->hits >= ship->size) {
            ship->isAfloat = false; // Ship is sunk
            return true; // Shows the ship was sunk
        }
        return true; // Shows the ship was hit
    }
    return false; // No ship was found or that the ship already sunk
}

// Checks if a ship with the given symbol is sunk.
// Returns true if the ship is sunk or doesn't exist and false otherwise.
bool ShipItems::isShipSunk(char symbol) const {
    
    Ship* ship = getShip(symbol);
    
    return !ship || !ship->isAfloat; // The ship doesn't exist or is not afloat
}

// Checks if all ships in the collection are sunk then.
// returns true if all ships are sunk and false otherwise.
bool ShipItems::areAllShipsSunk() const {
    
    Ship* current = head;
    
    while (current) {
        
        if (current->isAfloat) {
            
            return false;  
        }
        current = current->next;
    }
    return true; // All the ships are sunk
}

// This gets a ship from the collection based on its symbol then
// returns a pointer to the ship object if found and nullptr otherwise.
Ship* ShipItems::getShip(char symbol) const {
    
    Ship* current = head;
    
    while (current) {
        
        if (current->symbol == symbol) {
            
            return current; // Ship found
        }
        current = current->next;
    }
    return nullptr; // Ship not found
}

// This returns the size of a ship based on the given symbol.
int ShipItems::getShipSize(char symbol) const {
    
    Ship* ship = getShip(symbol);
    
    if (ship) {
        
        return ship->size;
    }
    return 0; // Ship not found and returns 0
}