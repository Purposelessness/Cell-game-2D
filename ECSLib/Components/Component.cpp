#include "Component.h"

int Component::getId() const {
    return _id;
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
    return std::to_string(_id) + "\n";
}

int Component::getEntityId() const {
    return _entity_id;
}

void Component::linkEntity(int entity_id) {
    _entity_id = entity_id;
}
