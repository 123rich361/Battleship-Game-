#include "GamePlayer.h"

// Constructor: This sets up the GamePlayer with the given player number.
GamePlayer::GamePlayer(int playerNumber) : playerID(playerNumber) {}

// Virtual Destructor: This makes sure that when a derived class is deleted it cleans up properly.
GamePlayer::~GamePlayer() {}

// Gets the player's ID.
int GamePlayer::getPlayerID() const {
    
    return playerID;
}