#ifndef GAME_ECS_SYSTEMS_ADDMONEYSYSTEM_H_
#define GAME_ECS_SYSTEMS_ADDMONEYSYSTEM_H_

#include "../../ECSLib/Systems/TickableSystem.h"

class AddMoneySystem : public TickableSystem {
public:
    void process() override;
};

#endif //GAME_ECS_SYSTEMS_ADDMONEYSYSTEM_H_