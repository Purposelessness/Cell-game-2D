#ifndef GAME_ECSLIB_COMPONENTS_COMPONENTBAG_H_
#define GAME_ECSLIB_COMPONENTS_COMPONENTBAG_H_

#include <unordered_map>
#include <memory>
#include <unordered_set>
#include <algorithm>
#include <tuple>

#include "../../Utility/Tuple.h"
#include "Component.h"

class ComponentBag : public IConvertibleToString {
public:
    template<TComponent T>
    std::shared_ptr<T> getComponent() {
        auto id = TypeIdentifier<T>::getId();;
        if (_components.count(id) < 1)
            return nullptr;
        return std::reinterpret_pointer_cast<T>(_components[id]);
    }

    template<TComponent T>
    void addComponent() {
        TypeIdentifier<T>::setup();
        auto id = TypeIdentifier<T>::getId();
        if (_components.count(id) > 0) {
            // TODO: log warning
            return;
        }
        _components[id] = std::make_shared<T>();
    }

    template<TComponent T>
    void setState(bool state) {
        auto id = TypeIdentifier<T>::getId();
        if (_components.count(id) < 1) {
            // TODO: log warning
            return;
        }
        state ? _components[id]->enable() : _components[id]->disable();
    }

    template<TComponent T>
    void removeComponent() {
        auto id = TypeIdentifier<T>::getId();
        if (_components.count(id) < 1) {
            // TODO: log warning
            return;
        }
        _components[id]->remove();
        _components[id].reset();
        _components.erase(id);
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
                           if (!components->contains(t.getId())) {
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
    std::unordered_map<int, std::shared_ptr<Component>> _components;
};

#endif //GAME_ECSLIB_COMPONENTS_COMPONENTBAG_H_