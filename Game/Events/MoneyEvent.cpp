#include "MoneyEvent.h"

#include "../../ECSLib/Core/Filter.h"
#include "../../ECS/Components/Money.h"
#include "../../Utility/Log/Log.h"

void MoneyEvent::invoke() {
    if (world == nullptr || !is_active)
        return;
    auto filter = Filter::with<Money>(*world);
    for (auto& e : filter) {
        e.getComponent<Money>().value += _money;
        LOG_TRACE << ("Money changed: " + std::to_string(e.getComponent<Money>().value));
    }
    is_active = false;
}
