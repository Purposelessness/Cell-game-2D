#include "Health.h"

Health::Health() : Component(this) {}

std::string Health::toString() const {
    return "Health:\n\tvalue: " + std::to_string(value) + "\n";
}
