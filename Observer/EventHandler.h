#ifndef GAME_EVENTHANDLER_H
#define GAME_EVENTHANDLER_H


#include <map>

#include "EventListener.h"

class EventHandler {
public:
    void subscribe(EventListener *listener);
    void unsubscribe(EventListener *listener);

    void notify(EventMessage *e);

private:
    std::map<int, EventListener *> listeners;
};


#endif //GAME_EVENTHANDLER_H