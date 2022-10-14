#ifndef GAME_FIELD_FIELDEVENTMESSAGE_H_
#define GAME_FIELD_FIELDEVENTMESSAGE_H_

#include <vector>

#include "../Datatypes/Point.h"
#include "../Datatypes/Size.h"

struct FieldEventMessage {
    std::vector<Point> information{};
    Size size{};
};

#endif //GAME_FIELD_FIELDEVENTMESSAGE_H_
