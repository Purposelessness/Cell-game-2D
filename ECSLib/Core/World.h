#ifndef GAME_ECSLIB_CORE_WORLD_H_
#define GAME_ECSLIB_CORE_WORLD_H_

#include <unordered_set>
#include <memory>
#include <vector>

#include "../Components/Component.h"
#include "Entity.h"

class World {
public:
    template<TComponent... Components>
    std::vector<std::shared_ptr<Entity>> filter() {
        std::vector<std::shared_ptr<Entity>> out;
        for (const auto& kEntity : _entities) {
            if (kEntity->component_bag.hasComponents<Components...>()) {
                out.push_back(kEntity);
            }
        }
        return out;
    }

    void addEntity(std::shared_ptr<Entity> entity);
    void removeEntity(const std::shared_ptr<Entity>& entity);

private:
    std::unordered_set<std::shared_ptr<Entity>> _entities;
};

#endif //GAME_ECSLIB_CORE_WORLD_H_