#ifndef GAME_GAME_GAMECONTROLLER_H_
#define GAME_GAME_GAMECONTROLLER_H_

#include <memory>

#include "../Engine/Input/IController.h"
#include "IGame.h"

class GameController : public IController {
public:
    explicit GameController(const std::weak_ptr<IGame>& game);

    void process(const InputMessage& input_message) override;

private:
    std::weak_ptr<IGame> _game;
};

#endif //GAME_GAME_GAMECONTROLLER_H_