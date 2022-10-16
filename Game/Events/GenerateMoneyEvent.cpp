#include "GenerateMoneyEvent.h"
#include "../../Utility/Log.h"

void GenerateMoneyEvent::invoke() {
    if (field_generator == nullptr || !is_active)
        return;
    is_active = false;
    field_generator->addMoneyEvents(_money_count);
    std::string out = "Money generated: " + std::to_string(_money_count);
    Log::instance()(std::move(out));
}
