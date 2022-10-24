#include "System.h"

void System::setWorld(std::weak_ptr<World> new_world) {
    world = std::move(new_world);
}

void System::resetWorld() {
    world.reset();
}
