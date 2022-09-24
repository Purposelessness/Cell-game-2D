#include "Health.h"

Health::Health() : Component(this) {}

std::string Health::toString() {
    return "Health:\n\tvalue: " + std::to_string(value) + "\n";
}
