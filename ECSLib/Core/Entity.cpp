#include "Entity.h"

#include <utility>

Entity::Entity(std::string name) : _name(std::move(name)) {}

std::string Entity::toString() {
    std::string out;
    out = "------------------";
    out += "Entity:" + _name + '\n' + component_bag.toString();
    out += "------------------";
    return out;
}
