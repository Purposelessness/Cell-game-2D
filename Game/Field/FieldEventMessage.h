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

    inline explicit operator std::string() const {
        return typeToString(type) + " on " + static_cast<std::string>(position);
    }

    static inline std::string typeToString(Type type) {
        switch (type) {
            case CellEventChanged:
                return "Cell event changed";
            case CellPassabilityChanged:
                return "Cell passability changed";
            case PlayerStepped:
                return "Player stepped";
            case PlayerLeft:
                return "Player left";
            default:
                return "Unknown FieldEventType";
        }
    }

    Point position;
    Type type;
};

#endif //GAME_GAME_FIELD_FIELDEVENTMESSAGE_H_
