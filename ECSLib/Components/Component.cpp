#include "Component.h"

Component::Component() : _type("Unknown"), _enabled(true), _deleted(false) {}

Component::Component(std::string type) : _type(std::move(type)), _enabled(true), _deleted(false) {}

std::string Component::getType() {
    return _type;
}

bool Component::isEnabled() const {
    return _enabled;
}

void Component::enable() {
    _enabled = true;
}

void Component::disable() {
    _enabled = false;
}

bool Component::isRemoved() const {
    return _deleted;
}

void Component::remove() {
    _deleted = true;
}

std::string Component::toString() {
    return _type + "\n";
}
