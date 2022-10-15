#ifndef GAME_GAME_FIELD_FIELDGENERATOR_H_
#define GAME_GAME_FIELD_FIELDGENERATOR_H_

#include "../Events/EventFactory.h"

class FieldGenerator {
public:
    void setEventFactory(std::weak_ptr<EventFactory> event_factory);

private:
    std::weak_ptr<EventFactory> _event_factory;
};

#endif //GAME_GAME_FIELD_FIELDGENERATOR_H_