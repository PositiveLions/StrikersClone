#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"
#include <string>

class Player : public Ship
{

public:

    Player();

    void update( float dt );
    void move();
    void attack( Ship &ship );



private:

    std::string  playerName;

    unsigned int playerScore;
};

#endif
