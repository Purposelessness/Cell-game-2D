#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H


#include <type_traits>

class Component;

template<typename T>
concept TComponent = std::is_base_of_v<Component, T>;

class Component {
public:
    Component();

    enum Type {
        Undefined = 0,
        Transform,
        Health,
    };

    Component::Type getType();

    void enable();
    void disable();
    [[nodiscard]] bool isEnabled() const;

    void remove();
    [[nodiscard]] bool isRemoved() const;

protected:
    explicit Component(Type type);

    Type type;

private:
    bool enabled;
    bool deleted;
};


#endif //GAME_COMPONENT_H