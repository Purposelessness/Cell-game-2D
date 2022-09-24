#include "Component.h"

int Component::getId() const {
    return _id;
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
