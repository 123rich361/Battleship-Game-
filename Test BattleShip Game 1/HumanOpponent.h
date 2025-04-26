#ifndef HUMANOPPONENT_H
#define HUMANOPPONENT_H

#include "GamePlayer.h"
#include "GameBoard.h"

class HumanOpponent : public GamePlayer {

public:
    HumanOpponent(int playerNumber);
    Coordinates getMove(GameBoard& board) override;
};

#endif