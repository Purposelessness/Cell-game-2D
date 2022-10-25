#include "DealDamageSystem.h"

#include "../Components/DealDamageEvent.h"
#include "../Components/Health.h"

#include "../../Utility/Log/Log.h"

void DealDamageSystem::process() {
    auto w = world.lock();
    auto cache = CommonCache::getCache<DealDamageEvent>();
    for (auto& key : cache.getKeys()) {
        auto damage = cache.getComponent(key);
        damage.target.getComponent<Health>().value -= damage.value;
        LOG_TRACE_F(static_cast<std::string>(damage.target) + " - health changed to " + std::to_string(damage.target.getComponent<Health>().value));
        w->removeEntity(key);
    }
}
