#ifndef GAME_ECS_SYSTEMS_CLEANDEADSYSTEM_H_
#define GAME_ECS_SYSTEMS_CLEANDEADSYSTEM_H_

#include "../../ECSLib/Systems/TickableSystem.h"
#include "../../Game/IGame.h"

class CleanDeadSystem : public TickableSystem {
public:
    explicit CleanDeadSystem(std::weak_ptr<IGame> game);

    void process() override;

private:
    std::weak_ptr<IGame> _game;
};

#endif //GAME_ECS_SYSTEMS_CLEANDEADSYSTEM_H_