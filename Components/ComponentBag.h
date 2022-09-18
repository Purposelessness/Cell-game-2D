#ifndef GAME_COMPONENTS_COMPONENTBAG_H_
#define GAME_COMPONENTS_COMPONENTBAG_H_

#include <unordered_map>
#include <memory>
#include <unordered_set>
#include <algorithm>
#include <tuple>

#include "../Utility/Tuple.h"
#include "Component.h"

class ComponentBag : public IConvertibleToString {
public:
    template<TComponent T>
    std::shared_ptr<T> getComponent() {
        T t;
        auto type = t.getType();
        if (_components.count(type) < 1)
            return nullptr;
        return std::reinterpret_pointer_cast<T>(_components[type]);
    }

    template<TComponent T>
    void addComponent() {
        T t;
        auto type = t.getType();
        if (_components.count(type) > 0) {
            // TODO: log warning
            return;
        }
        _components[type] = std::make_shared<T>();
    }

    template<TComponent T>
    void setState(bool state) {
        T t;
        auto type = t.getType();
        if (_components.count(type) < 1) {
            // TODO: log warning
            return;
        }
        state ? _components[type]->enable() : _components[type]->disable();
    }

    template<TComponent T>
    void removeComponent() {
        T t;
        auto type = t.getType();
        if (_components.count(type) < 1) {
            // TODO: log warning
            return;
        }
        _components[type]->remove();
        _components[type].reset();
        _components.erase(type);
    }

    template<TComponent... T>
    bool hasComponents() {
        using TypesTuple = std::tuple<T...>;
        TypesTuple types;
        bool out = true;
        Tuple::forEach(std::move(types),
                       [&out, components = &_components](TComponent auto t) {
                           if (!out)
                               return;
                           if (!components->contains(t.getType())) {
                               out = false;
                               return;
                           }
                       });
        return out;
    }

    std::string toString() override;

    ~ComponentBag();

private:
    std::vector<std::shared_ptr<Component>> getActiveComponents();
    std::unordered_map<std::string, std::shared_ptr<Component>> _components;
};

#endif //GAME_COMPONENTS_COMPONENTBAG_H_