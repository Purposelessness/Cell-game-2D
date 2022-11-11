#ifndef GAME_GAME_FIELD_GENERATOR_EVENTPLACER_H_
#define GAME_GAME_FIELD_GENERATOR_EVENTPLACER_H_

#include "../../Events/EventFactory.h"
#include "../Cell.h"
#include "Randomizer.h"

template <TEvent T, TRandomizer Rand = True>
class EventPlacer {
 public:
  explicit EventPlacer(EventFactory& factory, bool force_place = true)
      : _force_place(force_place), _factory(factory) {}

  void operator()(Cell& cell) const {
    if (!_randomizer()) {
      return;
    }
    cell.changeEvent(_factory.get<T>());
    if (_force_place) {
      cell.changePassability(true);
    }
  }

 private:
  bool _force_place;
  EventFactory& _factory;
  Rand _randomizer;
};

#endif
