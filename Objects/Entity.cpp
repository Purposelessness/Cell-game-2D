#include "Entity.h"

#include <utility>

Entity::Entity(std::string name) : name(std::move(name)) {}

std::string Entity::toString() {
    std::string out;
    out = "------------------";
    out += "Entity:" + name + '\n' + componentBag.toString();
    out += "------------------";
    return out;
}
