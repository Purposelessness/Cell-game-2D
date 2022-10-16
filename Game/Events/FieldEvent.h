#ifndef GAME_GAME_EVENTS_FIELDEVENT_H_
#define GAME_GAME_EVENTS_FIELDEVENT_H_

#include <memory>

#include "Event.h"
#include "../Field/FieldGenerator.h"

class FieldEvent : public Event {
public:
    explicit FieldEvent(std::shared_ptr<FieldGenerator> field_generator = nullptr);

    void setFieldGenerator(std::shared_ptr<FieldGenerator> field_generator);

protected:
    std::shared_ptr<FieldGenerator> field_generator;
};

#endif //GAME_GAME_EVENTS_FIELDEVENT_H_