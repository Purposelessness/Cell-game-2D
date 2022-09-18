#ifndef GAME_UTILITY_EVENTHANDLER_H_
#define GAME_UTILITY_EVENTHANDLER_H_


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


#endif //GAME_UTILITY_EVENTHANDLER_H_