#ifndef GAME_ECS_COMPONENTS_WEAPON_H_
#define GAME_ECS_COMPONENTS_WEAPON_H_

#include "../../ECSLib/Components/Component.h"

struct Weapon : public Component {
    Weapon();

    explicit operator std::string() const override;

    int damage = 5;
};

#endif //GAME_ECS_COMPONENTS_WEAPON_H_