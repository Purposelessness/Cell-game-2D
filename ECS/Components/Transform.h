#ifndef GAME_ECS_COMPONENTS_TRANSFORM_H_
#define GAME_ECS_COMPONENTS_TRANSFORM_H_

#include "../../ECSLib/Components/Component.h"
#include "../../Datatypes/Point.h"

class Field;

struct Transform : public Component {
    Transform();

    explicit operator std::string() const override;

    Point position{};
    int field_id = 0;
};

#endif //GAME_ECS_COMPONENTS_TRANSFORM_H_