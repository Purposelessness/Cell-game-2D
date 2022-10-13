#include "World.h"

#include "Entity.h"
#include "../Systems/System.h"
#include "../Systems/TickableSystem.h"

World::~World() {
    for (auto& entity : _entities) {
        CommonCache::clearEntity(entity.getId());
    }
}

Entity& World::addEntity(const std::string& name) {
    std::string entity_name = name;
    bool is_from_array;
    int id = getEntityId(is_from_array);
    if (name.empty()) {
        entity_name = "Entity " + std::to_string(id);
    }
    Entity entity{id, entity_name};
    if (is_from_array) {
        _entities.push_back(entity);
    } else {
        _entities[id] = entity;
    }
    return _entities[id];
}

void World::removeEntity(const Entity& entity) {
    int id = entity.getId();
    _entities[id] = Entity{};
    _unused_ids.push_back(id);
}

int World::getEntityId(bool& is_from_array) {
    if (_unused_ids.empty()) {
        is_from_array = true;
        return static_cast<int>(_entities.size());
    }
    int index = _unused_ids.back();
    _unused_ids.pop_back();
    is_from_array = false;
    return index;
}

void World::tick() {
    for (auto& system : _tickable_systems) {
        system->tick();
    }
}

