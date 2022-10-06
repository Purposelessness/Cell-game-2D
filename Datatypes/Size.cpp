#include "Size.h"

Size::Size(int x, int y) : x(x), y(y) {}

std::string Size::toString() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

bool Size::isNull() const {
    return x == 0 || y == 0;
}

Size& Size::operator+=(const Size& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Size operator+(const Size& a, const Size& b) {
    Size temp{a};
    temp += b;
    return temp;
}


