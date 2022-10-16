#ifndef GAME_GAME_EVENTS_ENEMYEVENT_H_
#define GAME_GAME_EVENTS_ENEMYEVENT_H_

#include <memory>

#include "WorldEvent.h"

class EnemyEvent : public WorldEvent {
public:
    void invoke() override;

private:
    int _money = 2;
    int _damage = 30;
};

#endif //GAME_GAME_EVENTS_ENEMYEVENT_H_