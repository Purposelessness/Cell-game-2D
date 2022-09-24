#ifndef GAME_ECSLIB_COMPONENTS_COMPONENTSCACHE_H_
#define GAME_ECSLIB_COMPONENTS_COMPONENTSCACHE_H_

#include <unordered_map>
#include <memory>
#include <vector>

#include "TypeIdentifier.h"
#include "ComponentConcept.h"

template<TComponent T>
class ComponentsCache;

class CommonCache {
public:
    template<TComponent T>
    static ComponentsCache<T>& getCache() {
        auto& cache = getCacheFast<T>();
        return reinterpret_cast<ComponentsCache<T>&>(cache);
    }

    template<TComponent T>
    static CommonCache& getCacheFast() {
        int cur_type_id = TypeIdentifier<T>::getId();
        if (caches[cur_type_id] == nullptr) {
            caches[cur_type_id] = std::make_shared<ComponentsCache<T>>();
        }
        return *caches[cur_type_id];
    }

    static std::shared_ptr<CommonCache> getCacheFast(int id) {
        return caches[id];
    }

    static void clearEntity(int entity_id) {
        for (auto& cache : caches) {
            cache.second->removeComponent(entity_id);
        }
    }

    virtual void removeComponent(int id) {}
    virtual bool hasComponent(int id) {
        return false;
    }

    [[nodiscard]] bool isEmpty() const;

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

    T& addComponent(int entity_id) {
        if (_data.contains(entity_id))
            return _data[entity_id];
        TComponent auto component = T{};
        component.linkEntity(entity_id);
        _data[entity_id] = component;
        _keys.emplace_back(entity_id);
        return _data[entity_id];
    }

    T& getComponent(int entity_id) {
        return _data[entity_id];
    }

    void removeComponent(int entity_id) override {
        if (!_data.contains(entity_id))
            return;
        _data.erase(entity_id);
        _keys.erase(std::remove(_keys.begin(), _keys.end(), entity_id)); // NOLINT(bugprone-inaccurate-erase)
    }

    bool hasComponent(int entity_id) override {
        return _data.contains(entity_id);
    }

    std::vector<int>& getKeys() {
        return _keys;
    }

private:
    std::vector<int> _keys;
    std::unordered_map<int, T> _data;
};

#endif //GAME_ECSLIB_COMPONENTS_COMPONENTSCACHE_H_