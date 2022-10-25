#include "DealDamageEvent.h"

DealDamageEvent::DealDamageEvent() : Component(this) {}

DealDamageEvent::operator std::string() const {
    return "[ DealDamageEvent | value: " + std::to_string(value) + ", target: " + static_cast<std::string>(target) + " ]";
}
