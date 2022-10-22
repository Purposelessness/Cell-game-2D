#ifndef GAME_ECS_COMPONENTS_MONEY_H_
#define GAME_ECS_COMPONENTS_MONEY_H_

#include "../../ECSLib/Components/Component.h"

struct Money : public Component {
    Money();

    explicit operator std::string() const override;

    int value = 0;
};

#endif //GAME_ECS_COMPONENTS_MONEY_H_