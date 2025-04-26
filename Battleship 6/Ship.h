#ifndef SHIP_H
#define SHIP_H

// This is a structure to represent a ship in the game and the variables are to indicate the character 
// of the ship symbol, the ships length in size, the hits that have occurred, to check if the boat is 
// still afloat, and pointer to the next ship in a linked list used in the ShipItems.
struct Ship {
    
    char symbol; 
    int size; 
    int hits; 
    bool isAfloat; 
    Ship* next; 
};

#endif