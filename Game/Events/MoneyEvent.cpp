#include "MoneyEvent.h"

#include "../../ECSLib/Core/Filter.h"
#include "../../ECS/Markers/PlayerMarker.h"
#include "../../ECS/Components/Money.h"
#include "../../Utility/Log/Log.h"
#include "../../ECS/Components/AddMoneyEvent.h"

void MoneyEvent::invoke() {
    if (world == nullptr || !is_active)
        return;
    auto filter = Filter::with<PlayerMarker, Money>(*world);
    for (auto& e : filter) {
        auto& money = world->addEntity(std::string{}).addComponent<AddMoneyEvent>();
        money.value = _money;
        money.target = e;
    }
    is_active = false;
}
