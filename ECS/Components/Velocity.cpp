#include "Velocity.h"

Velocity::Velocity() : Component(this) {}

std::string Velocity::toString() {
    return "Velocity:\n\tvalue: " + value.toString() + '\n';
}
