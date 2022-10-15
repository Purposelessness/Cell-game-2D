#include "ExitEvent.h"

#include "../../ECSLib/Core/Filter.h"
#include "../../ECS/Markers/PlayerMarker.h"
#include "../../ECS/Components/Money.h"
#include "../../Utility/Log.h"

ExitEvent::ExitEvent(std::weak_ptr<IGame> game) : _game(std::move(game)) {}

void ExitEvent::inject(std::shared_ptr<World> world) {
    _world = std::move(world);
}

void ExitEvent::invoke() {
    auto filter = Filter::with<PlayerMarker, Money>(*_world);
    for (auto& e : filter) {
        if (e.getComponent<Money>().value >= _win_money) {
            std::string out = e.getName() + " escaped";
            Log::instance()(std::move(out));
            _game.lock()->stop();
        }
    }
}
