#include "Velocity.h"

Velocity::Velocity() : Component(this) {}

Velocity::operator std::string() const {
  return "[ Velocity | value: " + static_cast<std::string>(value) + " ]";
}
