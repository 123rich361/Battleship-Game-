#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

#include "Coordinates.h"

class GameBoard; // This a forward declaration of the GameBoard class.

// Abstract base class for all game players whether human or computer.
class GamePlayer {

protected:
    int playerID; // This is a unique identifier for each of the player which helps to identify in the game.

public:
    GamePlayer(int playerNumber); // This is a constructor to initialize the player with their unique number..
    virtual ~GamePlayer(); // Virtual destructor for properly clean up resources.

    virtual Coordinates getMove(GameBoard& board) = 0; // Pure virtual function to get every player's move.
    int getPlayerID() const; // Gets the player's ID.
};

#endif