#ifndef GAME_ECSLIB_CORE_WORLD_H_
#define GAME_ECSLIB_CORE_WORLD_H_

#include <unordered_set>
#include <memory>
#include <vector>

#include "../Components/Component.h"
#include "Entity.h"

class Filter;

class World {
    friend class Filter;

public:
//    template<TComponent... Components>
//    std::vector<Entity> filter() {
//        for (const auto& kEntity : _entities) {
//            if (kEntity->component_bag.hasComponents<Components...>()) {
//                out.push_back(kEntity);
//            }
//        }
//        return out;
//        return {};
//    }

    Entity& addEntity(const std::string& name = std::string{});
    void removeEntity(const Entity& entity);

private:
    int getId(bool& is_from_array);

    std::vector<Entity> _entities;
    std::vector<int> _unused_ids;
};

#endif //GAME_ECSLIB_CORE_WORLD_H_