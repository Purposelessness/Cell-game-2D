#ifndef GAME_GAME_FIELD_FIELDEVENTMESSAGE_H_
#define GAME_GAME_FIELD_FIELDEVENTMESSAGE_H_

#include <utility>

#include "../../Datatypes/Point.h"

struct FieldEventMessage {
    enum Type {
        CellEventChanged,
        CellPassabilityChanged,
        PlayerStepped,
        PlayerLeft
    };

    FieldEventMessage(Point position, Type type) : position(std::move(position)), type(type) {}

    Point position;
    Type type;
};

#endif //GAME_GAME_FIELD_FIELDEVENTMESSAGE_H_
