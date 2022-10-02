#include "Component.h"

std::string Component::toString() const {
    return std::to_string(getId()) + "\n";
}

int Component::getEntityId() const {
    return _entity_id;
}

void Component::linkEntity(int entity_id) {
    _entity_id = entity_id;
}
