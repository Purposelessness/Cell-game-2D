#include "AddMoneyEvent.h"

AddMoneyEvent::AddMoneyEvent() : Component(this) {}

AddMoneyEvent::operator std::string() const {
  return "[ AddMoneyEvent | value: " + std::to_string(value) +
         ", target: " + static_cast<std::string>(target) + " ]";
}
