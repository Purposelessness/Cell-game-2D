#ifndef GAME_ECSLIB_SYSTEMS_SYSTEM_H_
#define GAME_ECSLIB_SYSTEMS_SYSTEM_H_

#include <memory>
#include <utility>

#include "../Core/Filter.h"

class World;

class System {
 public:
  virtual void process() = 0;
  virtual ~System() = default;

  void setWorld(std::weak_ptr<World> new_world);
  void resetWorld();

 protected:
  std::weak_ptr<World> world{};
};

#endif  // GAME_ECSLIB_SYSTEMS_SYSTEM_H_
