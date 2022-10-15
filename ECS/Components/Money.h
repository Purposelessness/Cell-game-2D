#ifndef GAME_ECS_COMPONENTS_MONEY_H_
#define GAME_ECS_COMPONENTS_MONEY_H_

#include "../../ECSLib/Components/Component.h"

struct Money : public Component {
    Money();

    [[nodiscard]] std::string toString() const override;

    int value = 0;
};

#endif //GAME_ECS_COMPONENTS_MONEY_H_