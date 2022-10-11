#include "Event.h"

#include <utility>

Event::Event(Point  position, int field_index) : _position(std::move(position)), _field_index(field_index) {}
