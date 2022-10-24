#ifndef GAME_GAME_EVENTS_GENERATEMONEYEVENT_H_
#define GAME_GAME_EVENTS_GENERATEMONEYEVENT_H_

#include <memory>

#include "FieldEvent.h"

class GenerateMoneyEvent : public FieldEvent {
public:
    void invoke() override;

private:
    int _max_money_count = 5;
};

#endif //GAME_GAME_EVENTS_GENERATEMONEYEVENT_H_