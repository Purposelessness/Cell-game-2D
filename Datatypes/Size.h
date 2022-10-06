#ifndef GAME_DATATYPES_SIZE_H_
#define GAME_DATATYPES_SIZE_H_

#include "../Utility/IConvertibleToString.h"

struct Size : IConvertibleToString {
    Size(int x = 0, int y = 0);

    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] bool isNull() const;

    Size& operator+=(const Size& other);
    friend Size operator+(const Size& a, const Size& b);
    Size& operator*=(int value);
    friend Size operator*(int value, const Size& size);
    friend Size operator*(const Size& size, int value);

    int x;
    int y;
};

#endif //GAME_DATATYPES_SIZE_H_