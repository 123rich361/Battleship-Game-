#include <iostream>
#include <cassert>
#include "GamePlayer.h"
#include "GameBoard.h"
#include "Coordinates.h"

using namespace std;

void testGamePlayerCreation() {
    
    cout << "Testing GamePlayer creation..." << endl;

    class MockGamePlayer : public GamePlayer {
    
    public:
        MockGamePlayer(int playerNumber) : GamePlayer(playerNumber) {}
        Coordinates getMove(GameBoard& board) override { return {0, 0}; }
        ~MockGamePlayer() override {} 
    };

    MockGamePlayer* player = new MockGamePlayer(1);
    
    assert(player->getPlayerID() == 1);
    delete player; 

    cout << "GamePlayer creation test passed." << endl;
}