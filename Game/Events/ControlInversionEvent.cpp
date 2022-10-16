#include "ControlInversionEvent.h"

#include "../../ECS/Markers/InvertControlMarker.h"
#include "../../ECS/Markers/PlayerMarker.h"
#include "../../ECSLib/Core/Filter.h"
#include "../../Utility/Log.h"

void ControlInversionEvent::invoke() {
    if (world == nullptr || !is_active)
        return;
    is_active = false;
    auto filter = Filter::with<PlayerMarker>(*world);
    for (auto& e : filter) {
        if (e.hasComponent<InvertControlMarker>()) {
            e.removeComponent<InvertControlMarker>();
        } else {
            e.addComponent<InvertControlMarker>();
        }
        Log::instance()("Controls inverted");
    }
}
