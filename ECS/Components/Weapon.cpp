#include "Weapon.h"

Weapon::Weapon() : Component(this) {}

std::string Weapon::toString() const {
    return "Weapon:\n\tdamage: " + std::to_string(damage) + '\n';
}
