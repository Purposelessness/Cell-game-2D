#ifndef GAME_CORE_GAMEDEPLOYER_H_
#define GAME_CORE_GAMEDEPLOYER_H_

#include "../ECSLib/Core/World.h"
#include "../Game/Game.h"

class GameDeployer {
public:
    static auto start(std::shared_ptr<World> world) {
        auto game = std::make_shared<Game>(std::move(world));
        return game;
    }
};

#endif //GAME_CORE_GAMEDEPLOYER_H_