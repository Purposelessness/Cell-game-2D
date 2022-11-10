#ifndef GAME_GAME_FIELD_GENERATOR_CELLCHANGER_H_
#define GAME_GAME_FIELD_GENERATOR_CELLCHANGER_H_

#include "../../Events/EventFactory.h"
#include "../Cell.h"

template <TEvent T>
class EventPlacer {
 public:
  explicit EventPlacer(EventFactory& factory) : _factory(factory) {}
  void operator()(Cell& cell) const { cell.changeEvent(_factory.get<T>()); }

 private:
  EventFactory& _factory;
};

template <bool Val>
class PassabilityPlacer {
 public:
  void operator()(Cell& cell) { cell.changePassability(Val); }
};

#endif
