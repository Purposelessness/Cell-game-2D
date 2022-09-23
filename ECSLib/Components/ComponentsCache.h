#ifndef GAME_ECSLIB_COMPONENTS_COMPONENTSCACHE_H_
#define GAME_ECSLIB_COMPONENTS_COMPONENTSCACHE_H_

#include <unordered_map>

#include "TypeIdentifier.h"
#include "Concept.h"
#include "../Core/Entity.h"

template<TComponent T>
class ComponentsCache;

class CommonCache {
public:
    template<TComponent T>
    static ComponentsCache<T>& getCache() {
        int cur_type_id = TypeIdentifier<T>::getId();
        if (caches[cur_type_id] == nullptr) {
            caches[cur_type_id] = std::make_shared<ComponentsCache<T>>();
        }
        auto& cache = *caches[cur_type_id];
        return reinterpret_cast<ComponentsCache<T>&>(cache);
    }

    virtual void removeComponent(const Entity& entity) = 0;
    virtual bool hasComponent(const Entity& entity) = 0;

protected:
    static std::unordered_map<int, std::shared_ptr<CommonCache>> caches;
    int type_id = -1;
};

template<TComponent T>
class ComponentsCache : public CommonCache {
public:
    ComponentsCache() {
        type_id = TypeIdentifier<T>::getId();
    }

    T& addComponent(const Entity& entity) {
        int entity_id = entity.getId();
        if (_data.contains(entity_id))
            return _data[entity_id];
        TComponent auto component = T{};
        component.linkEntity(entity_id);
        _data[entity_id] = component;
        keys.emplace_back(entity_id);
        return _data[entity_id];
    }

    T& getComponent(const Entity& entity) {
        return _data[entity.getId()];
    }

    T& getComponent(int key) {
        return _data[key];
    }

    void removeComponent(const Entity& entity) override {
        int entity_id = entity.getId();
        _data.erase(entity_id);
        keys.erase(std::remove(keys.begin(), keys.end(), entity_id)); // NOLINT(bugprone-inaccurate-erase)
    }

    bool hasComponent(const Entity& entity) override {
        return _data.contains(entity.getId());
    }

    std::vector<int> keys;

private:
    std::unordered_map<int, T> _data;
};

#endif //GAME_ECSLIB_COMPONENTS_COMPONENTSCACHE_H_