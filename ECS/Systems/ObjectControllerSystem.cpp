#include "ObjectControllerSystem.h"

#include "../../ECSLib/Core/Filter.h"
#include "../Markers/ControllableMarker.h"
#include "../Components/Velocity.h"

void ObjectControllerSystem::process(const InputMessage& input_message) {
    _message = input_message;
    process();
}

void ObjectControllerSystem::process() {
    if (world.expired())
        return;
    auto filter = Filter::with<ControllableMarker, Velocity>(*world.lock());
    for (auto& entity : filter) {
        auto& velocity = entity.getComponent<Velocity>();
        auto state = static_cast<int>(_message.state);
        switch (_message.type) {
            case InputType::MoveUp:
                velocity.value.y = -state;
                break;
            case InputType::MoveDown:
                velocity.value.y = state;
                break;
            case InputType::MoveRight:
                velocity.value.x = state;
                break;
            case InputType::MoveLeft:
                velocity.value.x = -state;
                break;
            default:
                break;
        }
    }
}
