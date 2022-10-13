#include "PlayerMarker.h"

PlayerMarker::PlayerMarker() : Component(this) {}

std::string PlayerMarker::toString() const {
    return "Player entity\n";
}
