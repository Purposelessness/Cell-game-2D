#ifndef GAME_OBJECTS_FIELD_FIELDEVENTMESSAGE_H_
#define GAME_OBJECTS_FIELD_FIELDEVENTMESSAGE_H_

#include <vector>
#include "../../Datatypes/Point.h"
#include "Cell.h"

struct FieldEventMessage {
    std::vector<Point> information{};
};

#endif //GAME_OBJECTS_FIELD_FIELDEVENTMESSAGE_H_
