#include "HealthSystem.h"
#include "../Components/Health.h"
#include "../Markers/DeadMarker.h"

void HealthSystem::process() {
    auto filter = Filter::with<Health>(*world.lock());
    for (auto& e : filter) {
        if (e.getComponent<Health>().value < 0) {
            e.addComponent<DeadMarker>();
        }
    }
}
