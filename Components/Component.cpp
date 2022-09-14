#include "Component.h"

Component::Component() : type("Unknown"), enabled(true), deleted(false) {}

Component::Component(std::string type) : type(std::move(type)), enabled(true), deleted(false) {}

std::string Component::getType() {
    return type;
}

bool Component::isEnabled() const {
    return enabled;
}

void Component::enable() {
    enabled = true;
}

void Component::disable() {
    enabled = false;
}

bool Component::isRemoved() const {
    return deleted;
}

void Component::remove() {
    deleted = true;
}
