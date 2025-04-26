#ifndef COMPUTEROPPONENT_H
#define COMPUTEROPPONENT_H

#include "GamePlayer.h"
#include "Coordinates.h"
#include <string>

using namespace std;

class GameBoard;
class ComputerOpponent : public GamePlayer {

private:
    string difficultyLevel;

public:
    ComputerOpponent(int playerNumber, string difficulty);
    Coordinates getMove(GameBoard& board) override;
};

#endif