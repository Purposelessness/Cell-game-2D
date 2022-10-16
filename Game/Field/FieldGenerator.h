#ifndef GAME_GAME_FIELD_FIELDGENERATOR_H_
#define GAME_GAME_FIELD_FIELDGENERATOR_H_

#include <memory>

class Field;
class EventFactory;

class FieldGenerator {
public:
    FieldGenerator();

    void setEventFactory(std::weak_ptr<EventFactory> event_factory);
    void setField(std::shared_ptr<Field> field);

    void addMoneyEvents(int max_count);

private:
    std::weak_ptr<EventFactory> _event_factory;
    std::shared_ptr<Field> _field;
};

#endif //GAME_GAME_FIELD_FIELDGENERATOR_H_