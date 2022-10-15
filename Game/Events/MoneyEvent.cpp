#include "MoneyEvent.h"

#include <utility>

#include "../../ECSLib/Core/Filter.h"
#include "../../ECS/Components/Money.h"
#include "../../Utility/Log.h"

void MoneyEvent::inject(std::shared_ptr<World> world) {
    _world = std::move(world);
}

void MoneyEvent::invoke() {
    if (_world == nullptr || !is_active)
        return;
    auto filter = Filter::with<Money>(*_world);
    for (auto& e : filter) {
        e.getComponent<Money>().value += _money;
        std::string out = "Money changed: " + std::to_string(e.getComponent<Money>().value);
        Log::instance()(std::move(out));
    }
    is_active = false;
}
