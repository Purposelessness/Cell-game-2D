#include "ControllableMarker.h"

ControllableMarker::ControllableMarker() : Component(this) {}

std::string ControllableMarker::toString() const {
    return "ControllableMarker\n";
}
