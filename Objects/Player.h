#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "Object.h"

class Player : public Object {
public:
    Player();
    explicit Player(int healthPoints, int damage, int intelligence);

private:
    int healthPoints;
    int damage;
    int intelligence;
};

#endif //GAME_PLAYER_H