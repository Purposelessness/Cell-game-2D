#ifndef GAME_GAME_EVENTS_MONEYEVENT_H_
#define GAME_GAME_EVENTS_MONEYEVENT_H_

#include <memory>

#include "Event.h"
#include "../../ECSLib/Core/World.h"

class MoneyEvent : public Event {
public:
    void inject(std::shared_ptr<World> world);
    void invoke() override;

private:
    std::shared_ptr<World> _world;
    int _money = 1;
};

#endif //GAME_GAME_EVENTS_MONEYEVENT_H_