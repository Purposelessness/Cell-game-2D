#include "Health.h"

Health::Health() : Component(this) {}

Health::operator std::string() const {
  return "[ Health | value: " + std::to_string(value) + " ]";
}
