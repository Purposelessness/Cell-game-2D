#include "CleanDeadSystem.h"
#include "../Markers/DeadMarker.h"
#include "../Markers/PlayerMarker.h"
#include "../../Utility/Log/Log.h"

CleanDeadSystem::CleanDeadSystem(std::weak_ptr<IGame> game) : _game(std::move(game)) {}

void CleanDeadSystem::process() {
    auto w = world.lock();
    auto filter = Filter::with<DeadMarker>(*w);
    for (auto& e : filter) {
        LOG_TRACE_F(static_cast<std::string>(e) + " is dead.");
        if (e.hasComponent<PlayerMarker>()) {
            _game.lock()->stop();
        }
        w->removeEntity(e);
    }
}
