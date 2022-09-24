#include "MovementSystem.h"

#include <utility>

#include "../../Objects/Field/Field.h"

MovementSystem::MovementSystem(std::vector<std::shared_ptr<Field>> fields) : _fields(std::move(fields)) {}

void MovementSystem::process() {
    auto filter = Filter::with<Velocity, Transform>(*world.lock());
    for (auto& entity : filter) {
        auto& velocity = entity.getComponent<Velocity>();
        auto& transform = entity.getComponent<Transform>();
        auto field_id = transform.field_id;
        if (field_id < 0 || field_id >= _fields.size()) {
            // TODO: log warning: "Unknown field id"
            continue;
        }
        auto& field = _fields[field_id];
        auto new_pos = field->normalizePoint(transform.position + velocity.value);
        if (!field->isPointPassable(new_pos)) {
            continue;
        }
        field->getCell(transform.position).onPlayerLeft();
        transform.position = new_pos;
        field->getCell(new_pos).onPlayerStepped();
    }
}
