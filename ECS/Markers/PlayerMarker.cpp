#include "PlayerMarker.h"

PlayerMarker::PlayerMarker() : Component(this) {}

PlayerMarker::operator std::string() const { return "[ PlayerMarker ]"; }
