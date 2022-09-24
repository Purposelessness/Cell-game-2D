#ifndef GAME_OBSERVER_EVENTMANAGER_H_
#define GAME_OBSERVER_EVENTMANAGER_H_

#include <map>

#include "EventListener.h"

class EventManager {
public:
    void subscribe(EventListener* listener);
    void unsubscribe(EventListener* listener);

    void notify(EventMessage* e);

private:
    std::map<int, EventListener*> _listeners;
};

#endif //GAME_OBSERVER_EVENTMANAGER_H_