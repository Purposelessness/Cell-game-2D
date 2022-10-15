#ifndef GAME_GAME_EVENTS_CONTROLINVERSIONEVENT_H_
#define GAME_GAME_EVENTS_CONTROLINVERSIONEVENT_H_

#include <memory>

#include "Event.h"
#include "../../ECSLib/Core/World.h"

class ControlInversionEvent : public Event {
public:
    void inject(std::shared_ptr<World> world);
    void invoke() override;

private:
    std::shared_ptr<World> _world = nullptr;
};

#endif //GAME_GAME_EVENTS_CONTROLINVERSIONEVENT_H_