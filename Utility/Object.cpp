#include "Object.h"

Object::Object() : Identified(this) {}

std::string Object::toString() const {
    return std::to_string(Identified::id);
}
