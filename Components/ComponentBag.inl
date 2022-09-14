std::string ComponentBag::toString() {
    std::string out;
    auto number = activeComponents.size();
    if (number < 1)
        return "No components\n";
    out += std::to_string(activeComponents.size()) + " components:\n";
    for (const auto &activeComponent : activeComponents) {
        out += components[activeComponent]->toString();
    }
    return out;
}
