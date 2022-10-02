#include "Intelligence.h"

Intelligence::Intelligence() : Component(this) {}

std::string Intelligence::toString() const {
    return "Intelligence:\t\nvalue: " + std::to_string(value) + '\n';
}
