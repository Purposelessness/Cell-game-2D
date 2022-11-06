#include "EnemyEvent.h"

#include "../../ECS/Components/AddMoneyEvent.h"
#include "../../ECS/Components/DealDamageEvent.h"
#include "../../ECS/Components/Health.h"
#include "../../ECS/Components/Money.h"
#include "../../ECS/Markers/PlayerMarker.h"
#include "../../ECSLib/Core/Filter.h"
#include "../../Utility/Log/Log.h"

void EnemyEvent::invoke() {
  if (!is_active) {
    return;
  }
  is_active = false;
  auto filter = Filter::with<PlayerMarker>(*world);
  for (auto& e : filter) {
    if (e.hasComponent<Money>()) {
      auto& event =
          world->addEntity(std::string{}).addComponent<AddMoneyEvent>();
      event.value = _money;
      event.target = e;
    }
    if (e.hasComponent<Health>()) {
      auto& event =
          world->addEntity(std::string{}).addComponent<DealDamageEvent>();
      event.target = e;
      event.value = _damage;
    }
  }
}
