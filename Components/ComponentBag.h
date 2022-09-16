#ifndef GAME_COMPONENTBAG_H
#define GAME_COMPONENTBAG_H


#include <unordered_map>
#include <memory>
#include <unordered_set>
#include <algorithm>
#include <tuple>

#include "../Utility/Helper.h"
#include "Component.h"

class ComponentBag : public IConvertibleToString {
public:
    template<TComponent T>
    std::shared_ptr<T> getComponent() {
        T t;
        auto type = t.getType();
        if (components.count(type) < 1)
            return nullptr;
        return std::reinterpret_pointer_cast<T>(components[type]);
    }

    template<TComponent T>
    void addComponent() {
        T t;
        auto type = t.getType();
        if (components.count(type) > 0) {
            // TODO: log warning
            return;
        }
        components[type] = std::make_shared<T>();
    }

    template<TComponent T>
    void setState(bool state) {
        T t;
        auto type = t.getType();
        if (components.count(type) < 1) {
            // TODO: log warning
            return;
        }
        state ? components[type]->enable() : components[type]->disable();
    }

    template<TComponent T>
    void removeComponent() {
        T t;
        auto type = t.getType();
        if (components.count(type) < 1) {
            // TODO: log warning
            return;
        }
        components[type]->remove();
        components[type].reset();
        components.erase(type);
    }

    template<TComponent... T>
    bool hasComponents() {
        using TypesTuple = std::tuple<T...>;
        TypesTuple types;
        bool out = true;
        Helper::forEach(std::move(types),
        [&out, components = &components](TComponent auto t) {
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
    std::unordered_map<std::string, std::shared_ptr<Component>> components;
};

#endif //GAME_COMPONENTBAG_H