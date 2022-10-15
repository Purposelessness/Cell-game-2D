#ifndef GAME_GAME_EVENTS_INVERTCONTROLEVENT_H_
#define GAME_GAME_EVENTS_INVERTCONTROLEVENT_H_

#include "../../ECSLib/Systems/System.h"
#include "IEvent.h"

class InvertControlEvent : public IEvent {
public:
    void inject(std::shared_ptr<World> world);
    void invoke() override;

private:
    std::shared_ptr<World> _world = nullptr;
};

#endif //GAME_GAME_EVENTS_INVERTCONTROLEVENT_H_