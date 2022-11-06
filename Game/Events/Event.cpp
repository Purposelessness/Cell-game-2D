#include "Event.h"

#include <utility>

Event::Event(Point position, int field_index)
    : position(std::move(position)), field_index(field_index) {}
