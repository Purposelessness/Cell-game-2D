#include "AddMoneySystem.h"

#include "../../Utility/Log/Log.h"
#include "../Components/AddMoneyEvent.h"
#include "../Components/Money.h"

void AddMoneySystem::process() {
  auto w = world.lock();
  auto cache = CommonCache::getCache<AddMoneyEvent>();
  for (auto& key : cache.getKeys()) {
    auto money = cache.getComponent(key);
    money.target.getComponent<Money>().value += money.value;
    LOG_TRACE_F(static_cast<std::string>(money.target) +
                " - money changed to " +
                std::to_string(money.target.getComponent<Money>().value));
    w->removeEntity(key);
  }
}
