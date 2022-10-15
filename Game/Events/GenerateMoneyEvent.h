#ifndef GAME_GAME_EVENTS_GENERATEMONEYEVENT_H_
#define GAME_GAME_EVENTS_GENERATEMONEYEVENT_H_

#include <memory>

#include "Event.h"
#include "../Field/FieldGenerator.h"

class GenerateMoneyEvent : public Event {
public:
    GenerateMoneyEvent();

    void inject(std::shared_ptr<FieldGenerator> field_generator);

    void invoke() override;

private:
    std::shared_ptr<FieldGenerator> _field_generator;
    int _money_count;
};

#endif //GAME_GAME_EVENTS_GENERATEMONEYEVENT_H_