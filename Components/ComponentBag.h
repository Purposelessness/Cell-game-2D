#ifndef GAME_COMPONENTBAG_H
#define GAME_COMPONENTBAG_H


#include <map>
#include <memory>
#include <vector>
#include <algorithm>

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
        activeComponents.emplace_back(type);
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
        activeComponents.erase(std::remove(activeComponents.begin(), activeComponents.end(), type),
                               activeComponents.end());
    }

    std::string toString() override;

private:
    std::vector<std::string> activeComponents;
    std::map<std::string, std::shared_ptr<Component>> components;
};

#include "ComponentBag.inl"

#endif //GAME_COMPONENTBAG_H