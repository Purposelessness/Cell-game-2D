#ifndef GAME_ECS_COMPONENTS_TRANSFORM_H_
#define GAME_ECS_COMPONENTS_TRANSFORM_H_

#include "../../ECSLib/Components/Component.h"
#include "../../Datatypes/Point.h"

class Field;

struct Transform : public Component {
    Transform();
    std::string toString() override;

    Point position = {};
    int field_id = 0;
};

#endif //GAME_ECS_COMPONENTS_TRANSFORM_H_