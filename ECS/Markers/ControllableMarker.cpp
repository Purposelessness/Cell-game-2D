#include "ControllableMarker.h"

ControllableMarker::ControllableMarker() : Component(this) {}

ControllableMarker::operator std::string() const {
    return "[ ControllableMarker ]";
}
