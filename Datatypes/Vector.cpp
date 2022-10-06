#include "Vector.h"

Vector::Vector(int x, int y) : x(x), y(y) {}

std::string Vector::toString() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

bool Vector::isNull() const {
    return x == 0 && y == 0;
}

Vector& Vector::operator+=(const Vector& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector Vector::operator+(const Vector& other) const {
    Vector copy{*this};
    copy += other;
    return copy;
}
