#ifndef GAME_GAME_FIELD_GENERATOR_EVENTPLACER_H_
#define GAME_GAME_FIELD_GENERATOR_EVENTPLACER_H_

#include "../../Events/EventFactory.h"
#include "../Cell.h"
#include "Randomizer.h"

template <TEvent T, TRandomizer Rand = True>
class EventPlacer {
 public:
  explicit EventPlacer(EventFactory& factory) : _factory(factory) {}

  void operator()(Cell& cell) const {
    if (!_randomizer()) {
      return;
    }
    cell.changeEvent(_factory.get<T>());
  }

 private:
  EventFactory& _factory;
  Rand _randomizer;
};


#endif
