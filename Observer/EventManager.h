#ifndef GAME_EVENTMANAGER_H
#define GAME_EVENTMANAGER_H


#include <map>

#include "EventListener.h"

class EventManager {
public:
    void subscribe(EventListener *listener);
    void unsubscribe(EventListener *listener);

    void notify(IEventMessage *e);

private:
    std::map<int, EventListener *> listeners;
};


#endif //GAME_EVENTMANAGER_H