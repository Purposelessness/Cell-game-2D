#include "ControlInversionEvent.h"

#include <utility>

#include "../../ECS/Markers/InvertControlMarker.h"
#include "../../ECS/Markers/PlayerMarker.h"
#include "../../ECSLib/Core/Filter.h"
#include "../../Utility/Log.h"

void ControlInversionEvent::invoke() {
    if (_world == nullptr || !is_active)
        return;
    is_active = false;
    auto filter = Filter::with<PlayerMarker>(*_world);
    for (auto& e : filter) {
        if (e.hasComponent<InvertControlMarker>()) {
            e.removeComponent<InvertControlMarker>();
        } else {
            e.addComponent<InvertControlMarker>();
        }
        Log::instance()("Controls inverted");
    }
}

void ControlInversionEvent::inject(std::shared_ptr<World> world) {
    _world = std::move(world);
}
