#include "Object.h"

Object::Object() : Identified(this) {}

Object::operator std::string() const {
    return "Object#" + std::to_string(Identified::id);
}