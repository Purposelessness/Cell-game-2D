#ifndef GAME_GAME_EVENTS_MONEYEVENT_H_
#define GAME_GAME_EVENTS_MONEYEVENT_H_

#include <memory>

#include "WorldEvent.h"

class MoneyEvent : public WorldEvent {
 public:
  void invoke() override;

 private:
  int _money = 1;
};

#endif  // GAME_GAME_EVENTS_MONEYEVENT_H_
