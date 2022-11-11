#ifndef GAME_GAME_FIELD_GENERATOR_PASSABILITYPLACER_H_
#define GAME_GAME_FIELD_GENERATOR_PASSABILITYPLACER_H_

#include "../../Events/EventFactory.h"
#include "../Cell.h"
#include "Randomizer.h"

template <bool Val, TRandomizer Rand = True>
class PassabilityPlacer {
 public:
  void operator()(Cell& cell) {
    if (!_randomizer()) {
      return;
    }
    cell.changePassability(Val);
  }

 private:
  Rand _randomizer;
};

#endif
