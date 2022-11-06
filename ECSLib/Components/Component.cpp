#include "Component.h"

int Component::getEntityId() const { return _entity_id; }

void Component::linkEntity(int entity_id) { _entity_id = entity_id; }

Component::operator std::string() const {
  return "[ Component#" + std::to_string(getId()) + " ]";
}
