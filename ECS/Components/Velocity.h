#ifndef GAME_ECS_COMPONENTS_VELOCITY_H_
#define GAME_ECS_COMPONENTS_VELOCITY_H_

#include "../../ECSLib/Components/Component.h"
#include "../../Datatypes/Vector.h"

struct Velocity : public Component {
    Velocity();

    [[nodiscard]] std::string toString() const override;

    Vector value;
};

#endif //GAME_ECS_COMPONENTS_VELOCITY_H_