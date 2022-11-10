#ifndef GAME_ECSLIB_CORE_WORLD_H_
#define GAME_ECSLIB_CORE_WORLD_H_

#include <memory>
#include <unordered_set>
#include <vector>

#include "../Components/Component.h"
#include "../Systems/TSystem.h"
#include "Entity.h"

class Filter;
class System;
class TickableSystem;

// TODO: get entity by id (and mb access through component cache)
class World : public std::enable_shared_from_this<World> {
  friend class Filter;

 public:
  ~World();

  void tick();

  Entity& addEntity(const std::string& name = std::string{});
  void removeEntity(const Entity& entity);
  void removeEntity(int id);

  template <TSystem T>
  void addSystem(std::shared_ptr<T> system) {
    system->setWorld(shared_from_this());
    if constexpr (std::is_base_of_v<TickableSystem, T>) {
      _tickable_systems.emplace_back(std::move(system));
    } else {
      _systems.emplace_back(std::move(system));
    }
  }

  template <TSystem T, typename... Args>
  std::shared_ptr<T> addSystem(Args&&... args) {
    auto system = std::make_shared<T>(std::forward<Args>(args)...);
    system->setWorld(shared_from_this());
    if constexpr (std::is_base_of_v<TickableSystem, T>) {
      _tickable_systems.emplace_back(system);
    } else {
      _systems.emplace_back(system);
    }
    return system;
  }

  template <TSystem T>
  void removeSystem(const std::shared_ptr<T>& system) {
    if constexpr (std::is_base_of_v<TickableSystem, T>) {
      _tickable_systems.erase(
          std::remove(_tickable_systems.begin(), _tickable_systems.end(),
                      system));  // NOLINT(bugprone-inaccurate-erase)
    } else {
      _systems.erase(std::remove(_systems.begin(), _systems.end(),
                                 system));  // NOLINT(bugprone-inaccurate-erase)
    }
    system->resetWorld();
  }

 private:
  int getEntityId(bool& is_from_array);

  std::vector<Entity> _entities;
  std::vector<int> _unused_ids;

  std::vector<std::shared_ptr<System>> _systems;
  std::vector<std::shared_ptr<TickableSystem>> _tickable_systems;
};

#endif  // GAME_ECSLIB_CORE_WORLD_H_
