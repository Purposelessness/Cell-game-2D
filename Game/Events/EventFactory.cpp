#include "EventFactory.h"

void EventFactory::setWorld(std::shared_ptr<World> world) {
  _world = std::move(world);
}

void EventFactory::setFieldChanger(
    std::shared_ptr<FieldChanger> field_changer) {
  _field_changer = std::move(field_changer);
}
