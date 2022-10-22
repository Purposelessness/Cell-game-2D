#include "Intelligence.h"

Intelligence::Intelligence() : Component(this) {}

Intelligence::operator std::string() const {
    return "[ Intelligence | value: " + std::to_string(value) + " ]";
}
