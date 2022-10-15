#include "FieldGenerator.h"

#include <utility>

void FieldGenerator::setEventFactory(std::weak_ptr<EventFactory> event_factory) {
    _event_factory = std::move(event_factory);
}
