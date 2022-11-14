#include "Point.h"

#include "Vector.h"

Point::Point(int x, int y) : x(x), y(y) {}

Point::Point(const Size& size) : x(size.x), y(size.y) {}

Point::operator std::string() const {
  return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
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

Point Point::operator+(const Point& b) {
  Point temp{*this};
  temp += b;
  return temp;
}

Point Point::operator+(const Vector& v) {
  Point temp{*this};
  temp += v;
  return temp;
}

Point Point::operator-(const Point& b) {
  Point temp{*this};
  temp -= b;
  return temp;
}

Point Point::operator-(const Vector& b) {
  Point temp{*this};
  temp -= b;
  return temp;
}
