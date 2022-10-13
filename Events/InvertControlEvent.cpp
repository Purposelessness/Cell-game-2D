#include "InvertControlEvent.h"

#include "../ECS/Markers/InvertControlMarker.h"
#include "../ECS/Markers/PlayerMarker.h"

void InvertControlEvent::process() {
    if (world.expired())
        return;
    auto filter = Filter::with<PlayerMarker>(*world.lock());
    for (auto& e : filter) {
        if (e.hasComponent<InvertControlMarker>()) {
            e.removeComponent<InvertControlMarker>();
        } else {
            e.addComponent<InvertControlMarker>();
        }
    }
}
