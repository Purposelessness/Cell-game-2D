#ifndef GAME_DATATYPES_POINT_H_
#define GAME_DATATYPES_POINT_H_

#include "../Utility/IConvertibleToString.h"

struct Vector;

struct Point : public IConvertibleToString {
    Point(int x, int y);

    std::string toString() override;

    friend Point operator+(Point& a, Point& b);
    friend Point operator+(Point& p, Vector& v);

    int x = -1;
    int y = -1;
};

#endif //GAME_DATATYPES_POINT_H_