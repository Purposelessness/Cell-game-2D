#ifndef GAME_DATATYPES_VECTOR_H_
#define GAME_DATATYPES_VECTOR_H_

#include "../Utility/IConvertibleToString.h"

struct Vector : public IConvertibleToString {
    Vector();
    Vector(int x, int y);

    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] bool isNull() const;

    int x = 0;
    int y = 0;
};

#endif //GAME_DATATYPES_VECTOR_H_