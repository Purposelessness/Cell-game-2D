#ifndef GAME_GAME_EVENTS_EXITEVENT_H_
#define GAME_GAME_EVENTS_EXITEVENT_H_

#include <memory>

#include "Event.h"
#include "../../ECSLib/Core/World.h"
#include "../IGame.h"

class ExitEvent : public Event {
public:
    explicit ExitEvent(std::weak_ptr<IGame> game);

    void inject(std::shared_ptr<World> world);
    void invoke() override;

private:
    std::weak_ptr<IGame> _game;
    std::shared_ptr<World> _world;
    int _win_money = 10;
};

#endif //GAME_GAME_EVENTS_EXITEVENT_H_