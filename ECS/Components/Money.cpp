#include "Money.h"

Money::Money() : Component(this) {}

std::string Money::toString() const {
    return "Money: " + std::to_string(value);
}
