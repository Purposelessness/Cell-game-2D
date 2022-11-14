#include "GameController.h"

#include <utility>

GameController::GameController(std::weak_ptr<IGame> game)
    : _game(std::move(game)) {}

void GameController::process(const InputMessage& input_message) {
  auto game = _game.lock();
  if (game == nullptr || input_message.state == InputState::Released) {
    return;
  }

  switch (input_message.type) {
    case InputType::Exit:
      game->stop();
      break;
    case InputType::Reset:
      game->reset();
      break;
    case InputType::Load:
      game->load();
      break;
    case InputType::Save:
      game->save();
      break;
    case InputType::Undefined:
    default:
      break;
  }
}
