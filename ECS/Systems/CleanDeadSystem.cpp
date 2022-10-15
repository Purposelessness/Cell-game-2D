#include "CleanDeadSystem.h"
#include "../Markers/DeadMarker.h"
#include "../Markers/PlayerMarker.h"
#include "../../Utility/Log.h"

CleanDeadSystem::CleanDeadSystem(std::weak_ptr<IGame> game) : _game(std::move(game)) {}

void CleanDeadSystem::process() {
    auto w = world.lock();
    auto filter = Filter::with<DeadMarker>(*w);
    for (auto& e : filter) {
        std::string out = e.getName() + " is dead.";
        Log::instance()(out);
        if (e.hasComponent<PlayerMarker>()) {
            _game.lock()->stop();
        }
        w->removeEntity(e);
    }
}
