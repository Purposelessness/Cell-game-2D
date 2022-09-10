#include "EventHandler.h"

void EventHandler::subscribe(EventListener *listener) {
    listeners[listener->getIndex()] = listener;
}

void EventHandler::unsubscribe(EventListener *listener) {
    listeners.erase(listener->getIndex());
}

void EventHandler::notify(IEventMessage *e) {
    for (auto listener : listeners) {
        listener.second->update(e);
    }
}
