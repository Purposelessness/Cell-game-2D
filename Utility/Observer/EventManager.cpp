#include "EventManager.h"

void EventManager::subscribe(EventListener *listener) {
  _listeners[listener->getIndex()] = listener;
}

void EventManager::unsubscribe(EventListener *listener) {
  _listeners.erase(listener->getIndex());
}

void EventManager::notify(EventMessage *e) {
  for (auto listener : _listeners) {
    listener.second->update(e);
  }
}
