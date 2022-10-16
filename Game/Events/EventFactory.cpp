#include "EventFactory.h"

void EventFactory::setWorld(std::shared_ptr<World> world) {
    _world = std::move(world);
}

void EventFactory::setFieldGenerator(std::shared_ptr<FieldGenerator> field_generator) {
    _field_generator = std::move(field_generator);
}
