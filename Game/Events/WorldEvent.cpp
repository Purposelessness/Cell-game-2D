#include "WorldEvent.h"

#include <utility>

WorldEvent::WorldEvent(std::shared_ptr<World>  world) : world(std::move(world)) {}

void WorldEvent::setWorld(std::shared_ptr<World> new_world) {
    world = std::move(new_world);
}
