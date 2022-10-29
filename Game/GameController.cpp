#include "GameController.h"

GameController::GameController(const std::weak_ptr<IGame>& game) : _game(game) {}

void GameController::process(const InputMessage& input_message) {
    auto game = _game.lock();
    if (game == nullptr)
        return;

    switch (input_message.type) {
        case InputType::Exit:
            game->stop();
            break;
        case InputType::Reset:
            game->stop();
            break;
        case InputType::Undefined:
        default:
            break;
    }
}
