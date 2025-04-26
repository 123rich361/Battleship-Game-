#include "GamePlayer.h"

GamePlayer::GamePlayer(int playerNumber) : playerID(playerNumber) {}

GamePlayer::~GamePlayer() {}

int GamePlayer::getPlayerID() const {
    
    return playerID;
}