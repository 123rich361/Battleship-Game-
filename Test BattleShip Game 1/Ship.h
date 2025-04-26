#ifndef SHIP_H
#define SHIP_H

struct Ship {
    
    char symbol;
    int size;
    int hits;
    bool isAfloat;
    Ship* next;
};

#endif