#include "EventFactory.h"

EventFactory::EventFactory(std::shared_ptr<World> world, std::shared_ptr<FieldGenerator> field_generator)
    : _world(std::move(world)), _field_generator(std::move(field_generator)) {}

void EventFactory::setWorld(std::shared_ptr<World> world) {
    _world = std::move(world);
}

void EventFactory::setFieldGenerator(std::shared_ptr<FieldGenerator> field_generator) {
    _field_generator = std::move(field_generator);
}
