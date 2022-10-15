#ifndef GAME_GAME_EVENTS_ENEMYEVENT_H_
#define GAME_GAME_EVENTS_ENEMYEVENT_H_

#include <memory>

#include "Event.h"
#include "../../ECSLib/Core/World.h"

class EnemyEvent : public Event {
public:
    void inject(std::shared_ptr<World> world);
    void invoke() override;

private:
    std::shared_ptr<World> _world;
    int _money = 2;
    int _damage = 30;
};

#endif //GAME_GAME_EVENTS_ENEMYEVENT_H_