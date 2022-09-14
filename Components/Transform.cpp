#include "Transform.h"

#include <utility>

#include "../Objects/Map/Field.h"

Transform::Transform() : Component("Transform") {
}

void Transform::setField(std::shared_ptr<Field> field) {
    this->field = std::move(field);
}

Point Transform::getPosition() const {
    return position;
}

bool Transform::setPosition(const Point &newPosition) {
    position = newPosition;
    return true;
}
