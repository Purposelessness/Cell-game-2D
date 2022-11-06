#ifndef GAME_CORE_GAMEDEPLOYER_H_
#define GAME_CORE_GAMEDEPLOYER_H_

#include "../ECSLib/Core/World.h"
#include "../Game/Game.h"

class GameDeployer final {
 public:
  static auto execute(IApplication* application,
                      const std::shared_ptr<World>& world) {
    auto game = std::make_shared<Game>(application, world);
    game->initialize();
    return game;
  }
};

#endif  // GAME_CORE_GAMEDEPLOYER_H_
