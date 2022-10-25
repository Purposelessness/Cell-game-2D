#ifndef GAME_ECS_COMPONENTS_DEALDAMAGEEVENT_H_
#define GAME_ECS_COMPONENTS_DEALDAMAGEEVENT_H_

#include "../../ECSLib/Components/Component.h"
#include "../../ECSLib/Core/Entity.h"

struct DealDamageEvent : public Component {
    DealDamageEvent();

    explicit operator std::string() const override;

    int value = 0;
    Entity target{};
};

#endif //GAME_ECS_COMPONENTS_DEALDAMAGEEVENT_H_