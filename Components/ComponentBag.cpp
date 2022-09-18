#include "ComponentBag.h"

std::string ComponentBag::toString() {
    std::string out;
    auto active_components = getActiveComponents();
    auto number = active_components.size();
    if (number < 1)
        return "No components\n";
    out += std::to_string(active_components.size()) + " components:\n";
    for (const auto& kComponent : active_components) {
        out += kComponent->toString();
    }
    return out;
}

std::vector<std::shared_ptr<Component>> ComponentBag::getActiveComponents() {
    std::vector<std::shared_ptr<Component>> out;
    for (const auto& kComponent : _components) {
        if (kComponent.second->isEnabled())
            out.push_back(kComponent.second);
    }
    return out;
}

ComponentBag::~ComponentBag() {
    for (auto& component : _components) {
        component.second->remove();
    }
}
