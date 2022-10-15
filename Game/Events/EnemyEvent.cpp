#include "EnemyEvent.h"

#include <utility>

#include "../../Utility/Log.h"

#include "../../ECSLib/Core/Filter.h"
#include "../../ECS/Components/Health.h"
#include "../../ECS/Markers/PlayerMarker.h"
#include "../../ECS/Components/Money.h"

void EnemyEvent::inject(std::shared_ptr<World> world) {
    _world = std::move(world);
}

void EnemyEvent::invoke() {
    if (_world == nullptr || !is_active)
        return;
    auto filter = Filter::with<PlayerMarker, Health>(*_world);
    for (auto& e : filter) {
        std::string out;
        if (e.hasComponent<Money>()) {
            e.getComponent<Money>().value += _money;
            out = "Money changed: " + std::to_string(e.getComponent<Money>().value);
            Log::instance()(std::move(out));
        }
        e.getComponent<Health>().value -= _damage;
        out = "Health changed: " + std::to_string(e.getComponent<Health>().value);
        Log::instance()(std::move(out));

    }
    is_active = false;
}
