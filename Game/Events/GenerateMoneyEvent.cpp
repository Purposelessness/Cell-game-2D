#include "GenerateMoneyEvent.h"
#include "../../Utility/Log.h"

GenerateMoneyEvent::GenerateMoneyEvent() : _money_count(5) {}

void GenerateMoneyEvent::inject(std::shared_ptr<FieldGenerator> field_generator) {
    _field_generator = std::move(field_generator);
}

void GenerateMoneyEvent::invoke() {
    if (_field_generator == nullptr || !is_active)
        return;
    is_active = false;
    _field_generator->addMoneyEvents(_money_count);
    std::string out = "Money generated: " + std::to_string(_money_count);
    Log::instance()(std::move(out));
}
