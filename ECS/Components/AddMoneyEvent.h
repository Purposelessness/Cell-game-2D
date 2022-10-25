#ifndef GAME_ECS_COMPONENTS_ADDMONEYEVENT_H_
#define GAME_ECS_COMPONENTS_ADDMONEYEVENT_H_

#include "../../ECSLib/Components/Component.h"
#include "../../ECSLib/Core/Entity.h"

struct AddMoneyEvent : public Component {
public:
    AddMoneyEvent();

    explicit operator std::string() const override;

    int value = 0;
    Entity target{};
};

#endif //GAME_ECS_COMPONENTS_ADDMONEYEVENT_H_