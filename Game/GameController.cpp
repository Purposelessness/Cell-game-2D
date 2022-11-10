#include "GameController.h"

#include <utility>

GameController::GameController(std::weak_ptr<IGame> game)
    : _game(std::move(game)) {}

void GameController::process(const InputMessage& input_message) {
  auto game = _game.lock();
  if (game == nullptr) {
    return;
  }

  switch (input_message.type) {
    case InputType::Exit:
      game->stop();
      break;
    case InputType::Reset:
      game->reset();
      break;
    case InputType::Undefined:
    default:
      break;
  }
}
