#include "ExitEvent.h"

#include "../../ECSLib/Core/Filter.h"
#include "../../ECS/Markers/PlayerMarker.h"
#include "../../ECS/Components/Money.h"
#include "../../Utility/Log/Log.h"

void ExitEvent::inject(std::weak_ptr<IGame> game) {
    _game = std::move(game);
}

void ExitEvent::invoke() {
    auto filter = Filter::with<PlayerMarker, Money>(*world);
    for (auto& e : filter) {
        if (e.getComponent<Money>().value >= _win_money) {
            LOG_TRACE_F(e.getName() + " escaped");
            _game.lock()->stop();
        }
    }
}
