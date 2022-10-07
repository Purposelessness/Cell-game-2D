#include "Point.h"

#include "Vector.h"

Point::Point(int x, int y) : x(x), y(y) {}

Point::Point(const Size& size) : x(size.x), y(size.y) {}

std::string Point::toString() const {
    return "(" + std::to_string(x) + "; " + std::to_string(y) + ")";
}

Point& Point::operator+=(const Point& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Point& Point::operator+=(const Vector& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Point operator+(const Point& a, const Point& b) {
    Point temp{a};
    temp += b;
    return temp;
}

Point operator+(const Point& p, const Vector& v) {
    Point temp{p};
    temp += v;
    return temp;
}

Point& Point::operator-=(const Point& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Point& Point::operator-=(const Vector& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Point operator-(const Point& a, const Point& b) {
    Point temp{a};
    temp -= b;
    return temp;
}

Point operator-(const Point& a, const Vector& b) {
    Point temp{a};
    temp -= b;
    return temp;
}
