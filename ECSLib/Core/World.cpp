#include "World.h"

#include "Entity.h"

void World::addEntity(std::shared_ptr<Entity> entity) {
    _entities.emplace(std::move(entity));
}

void World::removeEntity(const std::shared_ptr<Entity> &entity) {
    _entities.erase(entity);
}
