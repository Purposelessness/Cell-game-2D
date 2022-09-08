#include "Player.h"

Player::Player() : Player(100, 10, 3) {}

Player::Player(int healthPoints, int damage, int intelligence)
        : healthPoints(healthPoints), damage(damage), intelligence(intelligence) {}
