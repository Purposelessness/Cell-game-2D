#include "World.h"

#include "../Objects/Entity.h"

void World::addEntity(std::shared_ptr<Entity> entity) {
    entities.emplace(std::move(entity));
}

void World::removeEntity(const std::shared_ptr<Entity> &entity) {
    entities.erase(entity);
}
