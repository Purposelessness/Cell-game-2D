#ifndef GAME_ECSLIB_COMPONENTS_COMPONENT_H_
#define GAME_ECSLIB_COMPONENTS_COMPONENT_H_

#include <type_traits>
#include <string>

#include "../../Utility/IConvertibleToString.h"

class Component;

template<typename T>
concept TComponent = std::is_base_of_v<Component, T>;

class Component : public IConvertibleToString {
public:
    Component();

    std::string getType();

    void enable();
    void disable();
    [[nodiscard]] bool isEnabled() const;

    void remove();
    [[nodiscard]] bool isRemoved() const;

    std::string toString() override;

protected:
    explicit Component(std::string);

private:
    std::string _type;
    bool _enabled;
    bool _deleted;
};

#endif //GAME_ECSLIB_COMPONENTS_COMPONENT_H_