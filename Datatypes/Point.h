#ifndef GAME_DATATYPES_POINT_H_
#define GAME_DATATYPES_POINT_H_

#include "../Utility/IConvertibleToString.h"

struct Vector;

struct Point : public IConvertibleToString {
    Point();
    Point(int x, int y);

    std::string toString() override;

    friend Point operator+(Point& a, Point& b);
    friend Point operator+(Point& p, Vector& v);

    int x;
    int y;
};

#endif //GAME_DATATYPES_POINT_H_