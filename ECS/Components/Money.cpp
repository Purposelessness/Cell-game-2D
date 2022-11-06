#include "Money.h"

Money::Money() : Component(this) {}

Money::operator std::string() const {
  return "[ Money | value: " + std::to_string(value) + " ]";
}
