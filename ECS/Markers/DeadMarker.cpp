#include "DeadMarker.h"

DeadMarker::DeadMarker() : Component(this) {}

DeadMarker::operator std::string() const { return "[ DeadMarker ]"; }
