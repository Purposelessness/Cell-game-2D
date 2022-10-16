#include "MoneyEvent.h"

#include "../../ECSLib/Core/Filter.h"
#include "../../ECS/Components/Money.h"
#include "../../Utility/Log.h"

void MoneyEvent::invoke() {
    if (world == nullptr || !is_active)
        return;
    auto filter = Filter::with<Money>(*world);
    for (auto& e : filter) {
        e.getComponent<Money>().value += _money;
        std::string out = "Money changed: " + std::to_string(e.getComponent<Money>().value);
        Log::instance()(std::move(out));
    }
    is_active = false;
}
