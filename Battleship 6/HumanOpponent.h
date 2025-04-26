#ifndef HUMANOPPONENT_H
#define HUMANOPPONENT_H

#include "GamePlayer.h"
#include "GameBoard.h"

// This is a class HumanOpponent that represents a human player in the battleship game
class HumanOpponent : public GamePlayer {

public:
    HumanOpponent(int playerNumber); // This is a constructor to set up the human player.
    Coordinates getMove(GameBoard& board) override; // This gets the human player's move from user input.
};

#endif