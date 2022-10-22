#include "Size.h"

Size::Size(int x, int y) : x(x), y(y) {}

Size::operator std::string() const {
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

Size& Size::operator*=(int value) {
    x *= value;
    y *= value;
    return *this;
}

Size Size::operator+(const Size& b) {
    Size temp{*this};
    temp += b;
    return temp;
}

Size Size::operator*(int value) {
    Size temp{*this};
    temp *= value;
    return temp;
}
