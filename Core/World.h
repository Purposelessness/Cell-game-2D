#ifndef GAME_WORLD_H
#define GAME_WORLD_H


#include <unordered_set>
#include <memory>
#include <vector>

#include "../Components/Component.h"
#include "../Objects/Entity.h"

class World {
public:
    template<TComponent... Components>
    std::vector<std::shared_ptr<Entity>> filter() {
        std::vector<std::shared_ptr<Entity>> out;
        for (const auto &entity: entities) {
            if (entity->componentBag.hasComponents<Components...>()) {
                out.push_back(entity);
            }
        }
        return out;
    }

    void addEntity(std::shared_ptr<Entity> entity);
    void removeEntity(const std::shared_ptr<Entity> &entity);

private:
    std::unordered_set<std::shared_ptr<Entity>> entities;
};


#endif //GAME_WORLD_H