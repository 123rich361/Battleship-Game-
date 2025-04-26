#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

#include "Coordinates.h"

class GameBoard;
class GamePlayer {

protected:
    int playerID;

public:
    GamePlayer(int playerNumber);
    virtual ~GamePlayer();
    virtual Coordinates getMove(GameBoard& board) = 0;
    int getPlayerID() const;
};

#endif