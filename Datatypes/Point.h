#ifndef GAME_DATATYPES_POINT_H_
#define GAME_DATATYPES_POINT_H_

#include "../Utility/IConvertibleToString.h"
#include "Size.h"

struct Vector;

struct Point : public IConvertibleToString {
  explicit Point(int x = 0, int y = 0);
  explicit Point(const Size& size);

  explicit operator std::string() const override;

  Point& operator+=(const Point& other);
  Point& operator+=(const Vector& other);
  Point operator+(const Point& b);
  Point operator+(const Vector& v);

  Point& operator-=(const Point& other);
  Point& operator-=(const Vector& other);
  Point operator-(const Point& b);
  Point operator-(const Vector& b);

  int x;
  int y;
};

#endif  // GAME_DATATYPES_POINT_H_
