#ifndef GAME_ECSLIB_CORE_FILTER_H_
#define GAME_ECSLIB_CORE_FILTER_H_

#include "../Components/ComponentsCache.h"
#include "Entity.h"
#include "World.h"

class Filter {
 public:
  template <TComponent... Ts>
  static std::vector<Entity> with(World& world) {
    std::vector<Entity> out{};
    for (auto& entity : world._entities) {
      bool flag = true;
      (filter(TypeIdentifier<Ts>::getId(), entity, flag), ...);
      if (flag) {
        out.emplace_back(entity);
      }
    }
    return out;
  }

 private:
  inline static void filter(int type, const Entity& entity, bool& out) {
    if (!out) {
      return;
    }
    auto cache = CommonCache::getCacheFast(type);
    if (cache && cache->hasComponent(entity.getId())) {
      return;
    }
    out = false;
  }
};

#endif  // GAME_ECSLIB_CORE_FILTER_H_
