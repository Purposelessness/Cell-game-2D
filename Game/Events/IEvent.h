#ifndef GAME_GAME_EVENTS_IEVENT_H_
#define GAME_GAME_EVENTS_IEVENT_H_

#include <type_traits>

class IEvent {
 public:
  virtual ~IEvent() = default;
  virtual void invoke() = 0;
  virtual bool isActive() = 0;
};

#endif  // GAME_GAME_EVENTS_IEVENT_H_
