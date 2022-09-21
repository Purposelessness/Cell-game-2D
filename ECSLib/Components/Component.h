#ifndef GAME_ECSLIB_COMPONENTS_COMPONENT_H_
#define GAME_ECSLIB_COMPONENTS_COMPONENT_H_

#include <type_traits>
#include <string>

#include "Concept.h"
#include "TypeIdentifier.h"
#include "../../Utility/IConvertibleToString.h"

class Component : public IConvertibleToString {
public:
    [[nodiscard]] int getId() const;

    void enable();
    void disable();
    [[nodiscard]] bool isEnabled() const;

    void remove();
    [[nodiscard]] bool isRemoved() const;

    std::string toString() override;

protected:
    explicit Component(TComponent auto* tc) : _enabled(true), _deleted(false) {
        using ComponentType = std::remove_pointer_t<decltype(tc)>;
        TypeIdentifier<ComponentType>::setup();
        _id = TypeIdentifier<ComponentType>::getId();
    }

private:
    int _id;
    bool _enabled;
    bool _deleted;
};

#endif //GAME_ECSLIB_COMPONENTS_COMPONENT_H_