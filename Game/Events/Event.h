#ifndef GAME_GAME_EVENTS_EVENT_H_
#define GAME_GAME_EVENTS_EVENT_H_

#include "../../Datatypes/Point.h"
#include "IEvent.h"

class Event : public IEvent {
 public:
  explicit Event(Point position = Point{-1, -1}, int field_index = 0);
  void invoke() override = 0;

  bool isActive() override { return is_active; }

 protected:
  Point position;
  int field_index;
  bool is_active = true;
};

template <typename T>
concept TEvent = std::is_base_of_v<IEvent, T>;

#endif  // GAME_GAME_EVENTS_EVENT_H_
