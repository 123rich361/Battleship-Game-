#include "ShipItems.h"

ShipItems::ShipItems() : head(nullptr) {}

ShipItems::~ShipItems() {
    
    Ship* current = head;
    
    while (current != nullptr) {
        Ship* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

void ShipItems::addShip(char symbol, int size) {
    
    Ship* newShip = new Ship;
    newShip->symbol = symbol;
    newShip->size = size;
    newShip->hits = 0;
    newShip->isAfloat = true;
    newShip->next = head;
    head = newShip;
}

bool ShipItems::fireAtShip(char symbol) {
    
    Ship* ship = getShip(symbol);
    
    if (ship && ship->isAfloat) {
        ship->hits++;
        if (ship->hits >= ship->size) {
            ship->isAfloat = false;
            return true;
        }
        return true;
    }
    return false;
}

bool ShipItems::isShipSunk(char symbol) const {
    
    Ship* ship = getShip(symbol);
    return !ship || !ship->isAfloat;
}

bool ShipItems::areAllShipsSunk() const {
    
    Ship* current = head;
    while (current) {
        if (current->isAfloat) {
            return false;
        }
        current = current->next;
    }
    return true;
}

Ship* ShipItems::getShip(char symbol) const {
    
    Ship* current = head;
    while (current) {
        if (current->symbol == symbol) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

int ShipItems::getShipSize(char symbol) const {
    
    Ship* ship = getShip(symbol);
    if (ship) {
        return ship->size;
    }
    return 0;
}