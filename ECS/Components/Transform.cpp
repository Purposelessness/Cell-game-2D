#include "Transform.h"

Transform::Transform() : Component(this) {}

Transform::operator std::string() const {
  return "[ Transform | position: " + static_cast<std::string>(position) +
         "; field_id: " + std::to_string(field_id) + " ]";
}
