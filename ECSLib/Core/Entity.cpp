#include "Entity.h"

#include <utility>

Entity::Entity() : Entity(-1, "Entity") {}

Entity::Entity(int id, std::string name) : _id(id), _name(std::move(name)) {}

int Entity::getId() const {
    return _id;
}

Entity::operator std::string() const {
    return "{ " + _name + "#" + std::to_string(_id) + " }";
}

std::string Entity::getName() const {
    return _name;
}
