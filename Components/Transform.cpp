#include "Transform.h"

#include <utility>

#include "../Objects/Map/Field.h"

Transform::Transform() : Component("Transform") {
}

void Transform::setField(std::shared_ptr<Field> field) {
    this->_field = std::move(field);
}

Point Transform::getPosition() const {
    return _position;
}

bool Transform::setPosition(const Point& new_position) {
    _position = new_position;
    return true;
}
