#include "Entity.h"

#include <utility>

Entity::Entity() : Entity(-1, "empty") {}

Entity::Entity(int id, std::string name) : _id(id), _name(std::move(name)) {}

int Entity::getId() const {
    return _id;
}

std::string Entity::toString() {
    std::string out;
    out = "------------------";
//    out += "Entity:" + _name + '\n' + component_bag.toString();
    out += "Entity:" + _name + '\n';
    out += "------------------";
    return out;
}
