#include "Component.h"

Component::Type Component::getType() {
    return type;
}

Component::Component() : type(Undefined), enabled(true), deleted(false) {}

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

Component::Component(Component::Type type) : Component() {
    type = type;
}
