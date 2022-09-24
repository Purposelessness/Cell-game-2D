#include "Intelligence.h"

Intelligence::Intelligence() : Component(this) {}

std::string Intelligence::toString() {
    return "Intelligence:\t\nvalue: " + std::to_string(value) + '\n';
}
