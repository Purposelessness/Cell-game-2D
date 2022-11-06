#include "Weapon.h"

Weapon::Weapon() : Component(this) {}

Weapon::operator std::string() const {
  return "[ Weapon | damage: " + std::to_string(damage) + " ]";
}
