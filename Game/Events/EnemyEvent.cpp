#include "EnemyEvent.h"

#include "../../Utility/Log/Log.h"

#include "../../ECSLib/Core/Filter.h"
#include "../../ECS/Components/Health.h"
#include "../../ECS/Markers/PlayerMarker.h"
#include "../../ECS/Components/Money.h"

void EnemyEvent::invoke() {
    if (world == nullptr || !is_active)
        return;
    auto filter = Filter::with<PlayerMarker, Health>(*world);
    for (auto& e : filter) {
        std::string out;
        if (e.hasComponent<Money>()) {
            e.getComponent<Money>().value += _money;
            LOG_TRACE << ("Money changed: " + std::to_string(e.getComponent<Money>().value));
        }
        e.getComponent<Health>().value -= _damage;
        LOG_TRACE << ("Health changed: " + std::to_string(e.getComponent<Health>().value));
    }
    is_active = false;
}
