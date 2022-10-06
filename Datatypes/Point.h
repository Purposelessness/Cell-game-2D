#ifndef GAME_DATATYPES_POINT_H_
#define GAME_DATATYPES_POINT_H_

#include "../Utility/IConvertibleToString.h"

struct Vector;

struct Point : public IConvertibleToString {
    Point(int x = 0, int y = 0);

    [[nodiscard]] std::string toString() const override;

    Point& operator+=(const Point& other);
    Point& operator+=(const Vector& other);
    friend Point operator+(const Point& a, const Point& b);
    friend Point operator+(const Point& p, const Vector& v);

    int x;
    int y;
};

#endif //GAME_DATATYPES_POINT_H_