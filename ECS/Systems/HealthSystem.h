#ifndef GAME_ECS_SYSTEMS_HEALTHSYSTEM_H_
#define GAME_ECS_SYSTEMS_HEALTHSYSTEM_H_

#include "../../ECSLib/Systems/TickableSystem.h"

class HealthSystem : public TickableSystem {
public:
    void process() override;
};

#endif //GAME_ECS_SYSTEMS_HEALTHSYSTEM_H_