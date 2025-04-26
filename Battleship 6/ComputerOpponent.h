#ifndef COMPUTEROPPONENT_H
#define COMPUTEROPPONENT_H

#include "GamePlayer.h"
#include "Coordinates.h"
#include <string>

using namespace std;

class GameBoard; // This is a forward declaration of the GameBoard class.

// Class definition for ComputerOpponent representing a computer player.
class ComputerOpponent : public GamePlayer {

private:
    string difficultyLevel; // Stores the difficulty level of the computer player.

public:
    ComputerOpponent(int playerNumber, string difficulty); // Constructor to initialize the computer opponent.
    Coordinates getMove(GameBoard& board) override; // Gets the computer player's move.
};

#endif