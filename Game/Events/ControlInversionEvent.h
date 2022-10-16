#ifndef GAME_GAME_EVENTS_CONTROLINVERSIONEVENT_H_
#define GAME_GAME_EVENTS_CONTROLINVERSIONEVENT_H_

#include <memory>

#include "WorldEvent.h"

class ControlInversionEvent : public WorldEvent {
public:
    void invoke() override;
};

#endif //GAME_GAME_EVENTS_CONTROLINVERSIONEVENT_H_