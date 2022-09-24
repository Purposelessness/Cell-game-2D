#include "Transform.h"

Transform::Transform() : Component(this) {}

std::string Transform::toString() {
    return "Transform:\n\tposition: " + position.toString() + "\n\tfield_id: " + std::to_string(field_id) + "\n";
}
