#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H


#include <type_traits>
#include <string>

class Component;

template<typename T>
concept TComponent = std::is_base_of_v<Component, T>;

class Component {
public:
    Component();

    std::string getType();

    void enable();
    void disable();
    [[nodiscard]] bool isEnabled() const;

    void remove();
    [[nodiscard]] bool isRemoved() const;

protected:
    explicit Component(std::string);

private:
    std::string type;
    bool enabled;
    bool deleted;
};


#endif //GAME_COMPONENT_H