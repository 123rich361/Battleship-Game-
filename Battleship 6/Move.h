#ifndef MOVE_H
#define MOVE_H

// This is a structure to represent a move made in the game and the variables it has the row and column
// of the move as well as the playerID of the player who made the move and the previous value of 
// the game board before the move was made. 
struct Move {
    
    int row; 
    int col; 
    int playerID; 
    char previousValue; 
};

#endif