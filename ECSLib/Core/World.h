#ifndef GAME_ECSLIB_CORE_WORLD_H_
#define GAME_ECSLIB_CORE_WORLD_H_

#include <unordered_set>
#include <memory>
#include <vector>

#include "Entity.h"
#include "../Components/Component.h"
#include "../Systems/TSystem.h"

class Filter;
class System;
class TickableSystem;

class World : public std::enable_shared_from_this<World> {
    friend class Filter;

public:
    ~World();

    void tick();

    Entity& addEntity(const std::string& name = std::string{});
    void removeEntity(const Entity& entity);

    template<TSystem T>
    void addSystem(std::shared_ptr<T> system) {
        auto this_ptr = shared_from_this();
        auto weak_ptr = std::weak_ptr<World>(this_ptr);
        system->setWorld(weak_ptr);
        if constexpr (std::is_base_of_v<TickableSystem, T>) {
            _tickable_systems.emplace_back(std::move(system));
        } else {
            _systems.emplace_back(std::move(system));
        }
    }

    template<TSystem T>
    void removeSystem(std::shared_ptr<T> system) {
        if constexpr (std::is_base_of_v<TickableSystem, T>) {
            _tickable_systems.erase(std::remove(_tickable_systems.begin(),
                                                _tickable_systems.end(),
                                                system)); // NOLINT(bugprone-inaccurate-erase)
        } else {
            _systems.erase(std::remove(_systems.begin(), _systems.end(), system)); // NOLINT(bugprone-inaccurate-erase)
        }
        system->setWorld(shared_from_this());
        system->resetWorld();
    }

private:
    int getEntityId(bool& is_from_array);

    std::vector<Entity> _entities;
    std::vector<int> _unused_ids;

    std::vector<std::shared_ptr<System>> _systems;
    std::vector<std::shared_ptr<TickableSystem>> _tickable_systems;
};

#endif //GAME_ECSLIB_CORE_WORLD_H_