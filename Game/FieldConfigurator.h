#ifndef GAME_GAME_FIELDCONFIGURATOR_H_
#define GAME_GAME_FIELDCONFIGURATOR_H_

#include <memory>

#include "Field/Field.h"

class EventFactory;

class FieldConfigurator {
 public:
  static std::shared_ptr<Field> execute(EventFactory& event_factory);

  static std::shared_ptr<Field> defaultOption(EventFactory& event_factory);
  static std::shared_ptr<Field> rectOption(EventFactory& event_factory);
  static std::shared_ptr<Field> chaosOption(EventFactory& event_factory);
};

#endif
