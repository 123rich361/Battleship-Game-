#ifndef ATTACKRESULT_H
#define ATTACKRESULT_H

// This is a structure to represent the result of an attack and the
// variables are used to indicate whether the attack hit a ship, or 
//if it has been sunk, and the symbol of the ship hit by the attack.
struct AttackResult {
    
    bool hit; 
    bool sunk; 
    char shipSymbol; 
};

#endif