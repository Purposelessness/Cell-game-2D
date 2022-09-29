#include "Object.h"

Object::Object() : Identified(this) {}

std::string Object::toString() {
    return std::to_string(Identified::id);
}
