#ifndef GAME_GAME_FIELD_GENERATOR_FIELDCHANGER_H_
#define GAME_GAME_FIELD_GENERATOR_FIELDCHANGER_H_

#include <memory>

class Field;
class EventFactory;

class FieldChanger {
 public:
  FieldChanger();

  void setEventFactory(std::weak_ptr<EventFactory> event_factory);
  void setField(std::shared_ptr<Field> field);

  void addMoneyEvents(int money_count);

 private:
  std::weak_ptr<EventFactory> _event_factory;
  std::shared_ptr<Field> _field;
};

#endif
