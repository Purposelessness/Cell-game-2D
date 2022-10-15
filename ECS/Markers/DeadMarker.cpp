#include "DeadMarker.h"

DeadMarker::DeadMarker() : Component(this) {}

std::string DeadMarker::toString() const {
    return "DeadMarker\n";
}
