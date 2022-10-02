#ifndef GAME_ECS_COMPONENTS_HEALTH_H_
#define GAME_ECS_COMPONENTS_HEALTH_H_

#include "../../ECSLib/Components/Component.h"

struct Health : public Component {
    Health();

    [[nodiscard]] std::string toString() const override;

    int value = 100;
};

#endif //GAME_ECS_COMPONENTS_HEALTH_H_