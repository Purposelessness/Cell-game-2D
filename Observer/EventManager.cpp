#include "EventManager.h"

void EventManager::subscribe(EventListener *listener) {
    listeners[listener->getIndex()] = listener;
}

void EventManager::unsubscribe(EventListener *listener) {
    listeners.erase(listener->getIndex());
}

void EventManager::notify(IEventMessage *e) {
    for (auto listener : listeners) {
        listener.second->update(e);
    }
}
