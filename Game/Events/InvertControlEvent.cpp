#include "InvertControlEvent.h"

#include <utility>

#include "../../ECS/Markers/InvertControlMarker.h"
#include "../../ECS/Markers/PlayerMarker.h"

void InvertControlEvent::invoke() {
    if (_world == nullptr)
        return;
    auto filter = Filter::with<PlayerMarker>(*_world);
    for (auto& e : filter) {
        if (e.hasComponent<InvertControlMarker>()) {
            e.removeComponent<InvertControlMarker>();
        } else {
            e.addComponent<InvertControlMarker>();
        }
    }
}

void InvertControlEvent::inject(std::shared_ptr<World> world) {
    _world = std::move(world);
}
