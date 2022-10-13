#ifndef GAME_EVENTS_INVERTCONTROLEVENT_H_
#define GAME_EVENTS_INVERTCONTROLEVENT_H_

#include "../ECSLib/Systems/System.h"

class InvertControlEvent : public System {
public:
    void process() override;
};

#endif //GAME_EVENTS_INVERTCONTROLEVENT_H_