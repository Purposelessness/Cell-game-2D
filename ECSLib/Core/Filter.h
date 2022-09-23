#ifndef GAME_ECSLIB_CORE_FILTER_H_
#define GAME_ECSLIB_CORE_FILTER_H_

#include "Entity.h"
#include "World.h"
#include "../Components/ComponentsCache.h"

class Filter {
public:
    template<TComponent... Ts>
    std::vector<Entity> with(World& world) {
        std::vector<Entity> out{};
        auto filter = [](int type, const Entity& entity, bool& out) {
            if (!out)
                return;
            auto cache = CommonCache::getCacheFast(type);
            if (cache && cache->hasComponent(entity.getId())) {
                return;
            }
            out = false;
        };
        for (auto& entity : world._entities) {
            bool flag = true;
            (filter(TypeIdentifier<Ts>::getId(), entity, flag), ...);
            if (flag) {
                out.emplace_back(entity);
            }
        }
        return out;
    }
};

#endif //GAME_ECSLIB_CORE_FILTER_H_