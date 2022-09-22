#ifndef GAME_DATATYPES_POINT_H_
#define GAME_DATATYPES_POINT_H_

#include "../Utility/IConvertibleToString.h"

struct Point : public IConvertibleToString {
    std::string toString() override;

    int x = -1;
    int y = -1;
};

#endif //GAME_DATATYPES_POINT_H_