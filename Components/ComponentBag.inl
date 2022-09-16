
#include "ComponentBag.h"

std::string ComponentBag::toString() {
    std::string out;
    auto activeComponents = getActiveComponents();
    auto number = activeComponents.size();
    if (number < 1)
        return "No components\n";
    out += std::to_string(activeComponents.size()) + " components:\n";
    for (const auto &component : activeComponents) {
        out += component->toString();
    }
    return out;
}

std::vector<std::shared_ptr<Component>> ComponentBag::getActiveComponents() {
    std::vector<std::shared_ptr<Component>> out;
    for (const auto &component : components) {
        if (component.second->isEnabled())
            out.push_back(component.second);
    }
    return out;
}

ComponentBag::~ComponentBag() {
    for (auto &component : components) {
        component.second->remove();
        component.second.reset();
    }
}
