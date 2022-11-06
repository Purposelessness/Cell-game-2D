#ifndef GAME_GAME_EVENTS_WORLDEVENT_H_
#define GAME_GAME_EVENTS_WORLDEVENT_H_

#include <memory>

#include "../../ECSLib/Core/World.h"
#include "Event.h"

class WorldEvent : public Event {
 public:
  explicit WorldEvent(std::shared_ptr<World> world = nullptr);

  void setWorld(std::shared_ptr<World> world);

 protected:
  std::shared_ptr<World> world;
};

#endif  // GAME_GAME_EVENTS_WORLDEVENT_H_
