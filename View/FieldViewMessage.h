#ifndef GAME_VIEW_FIELDVIEWMESSAGE_H_
#define GAME_VIEW_FIELDVIEWMESSAGE_H_

#include <vector>

#include "../Engine/View/ViewMessage.h"
#include "../Datatypes/Point.h"

enum class FieldViewType;

struct FieldViewMessage : public ViewMessage {
    std::vector<std::pair<Point, FieldViewType>> changes;
};

enum class FieldViewType {
    Undefined,
    Cell,
    Wall,
    Player
};

#endif //GAME_VIEW_FIELDVIEWMESSAGE_H_
