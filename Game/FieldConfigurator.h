#ifndef GAME_GAME_FIELDCONFIGURATOR_H_
#define GAME_GAME_FIELDCONFIGURATOR_H_

#include <memory>

#include "Field/Field.h"

class EventFactory;

class FieldConfigurator {
 public:
  enum Option { Default, Rect, Chaos };

  explicit FieldConfigurator(std::shared_ptr<EventFactory> event_factory);

  std::shared_ptr<Field> execute();
  std::shared_ptr<Field> generate();

  std::shared_ptr<Field> defaultOption();
  std::shared_ptr<Field> rectOption();
  std::shared_ptr<Field> chaosOption();

 private:
  std::shared_ptr<EventFactory> _event_factory;
  Option _option;
};

#endif
