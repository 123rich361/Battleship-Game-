#ifndef SHIPITEMS_H
#define SHIPITEMS_H

#include "Ship.h"

class ShipItems {

private:
    Ship* head;

public:
    ShipItems();
    ~ShipItems();
    void addShip(char symbol, int size);
    bool fireAtShip(char symbol);
    bool isShipSunk(char symbol) const;
    bool areAllShipsSunk() const;
    Ship* getShip(char symbol) const;
    int getShipSize(char symbol) const;
};

#endif