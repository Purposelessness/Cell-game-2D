#include "Vector.h"

Vector::Vector() : Vector(0, 0) {}

Vector::Vector(int x, int y) : x(x), y(y) {}

std::string Vector::toString() {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

bool Vector::isNull() const {
    return x == 0 && y == 0;
}
