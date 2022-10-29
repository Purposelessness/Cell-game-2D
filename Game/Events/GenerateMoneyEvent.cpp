#include "GenerateMoneyEvent.h"
#include "../../Utility/Log/Log.h"

void GenerateMoneyEvent::invoke() {
    if (field_changer == nullptr || !is_active)
        return;
    is_active = false;
    int money_count = std::rand() % _max_money_count;
    field_changer->addMoneyEvents(money_count);
    LOG_TRACE_F("Money generated: " + std::to_string(money_count));
}
