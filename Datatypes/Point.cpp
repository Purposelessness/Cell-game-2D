#include "Point.h"

#include "Vector.h"

Point::Point() : Point(0, 0) {}

Point::Point(int x, int y) : x(x), y(y) {}

std::string Point::toString() {
    return "(" + std::to_string(x) + "; " + std::to_string(y) + ")";
}

Point operator+(Point& a, Point& b) {
    return Point{a.x + b.x, a.y + b.y};
}

Point operator+(Point& p, Vector& v) {
    return Point{p.x + v.x, p.y + v.y};
}
