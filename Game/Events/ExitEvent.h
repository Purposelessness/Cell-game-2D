#ifndef GAME_GAME_EVENTS_EXITEVENT_H_
#define GAME_GAME_EVENTS_EXITEVENT_H_

#include <memory>

#include "../IGame.h"
#include "WorldEvent.h"

class ExitEvent : public WorldEvent {
 public:
  void inject(std::weak_ptr<IGame> game);
  void invoke() override;

 private:
  std::weak_ptr<IGame> _game;
  int _win_money = 10;
};

#endif  // GAME_GAME_EVENTS_EXITEVENT_H_
