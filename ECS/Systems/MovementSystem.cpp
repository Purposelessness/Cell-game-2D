#include "MovementSystem.h"

#include <utility>

#include "../../Game/Field/Field.h"
#include "../../Utility/Log.h"
#include "../Markers/InvertControlMarker.h"

MovementSystem::MovementSystem(std::vector<std::shared_ptr<Field>> fields) : _fields(std::move(fields)) {}

void MovementSystem::process() {
    if (world.expired())
        return;
    auto filter = Filter::with<Velocity, Transform>(*world.lock());
    for (auto& entity : filter) {
        auto& velocity = entity.getComponent<Velocity>();
        if (velocity.value.isNull())
            continue;
        auto& transform = entity.getComponent<Transform>();
        auto field_id = transform.field_id;
        if (field_id < 0 || field_id >= _fields.size()) {
            Log::instance()("MovementSystem: unknown field id", Log::Warning);
            continue;
        }
        auto& field = _fields[field_id];

        Point new_pos;
        if (entity.hasComponent<InvertControlMarker>()) {
            new_pos = field->normalizePoint(transform.position - velocity.value);
        } else {
            new_pos = field->normalizePoint(transform.position + velocity.value);
        }

        if (!field->isPointPassable(new_pos)) {
            continue;
        }
        field->onPlayerLeft(transform.position);
        transform.position = new_pos;
        field->onPlayerStepped(new_pos);
    }
}
