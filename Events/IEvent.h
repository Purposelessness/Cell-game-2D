#ifndef GAME_EVENTS_IEVENT_H_
#define GAME_EVENTS_IEVENT_H_

#include <type_traits>

class IEvent {
public:
    virtual void invoke() = 0;
};

#endif //GAME_EVENTS_IEVENT_H_
