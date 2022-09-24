#ifndef GAME_ECSLIB_COMPONENTS_COMPONENT_H_
#define GAME_ECSLIB_COMPONENTS_COMPONENT_H_

#include <type_traits>
#include <string>

#include "ComponentConcept.h"
#include "TypeIdentifier.h"
#include "../../Utility/IConvertibleToString.h"

class Component : public IConvertibleToString {
public:
    [[nodiscard]] int getId() const;
    [[nodiscard]] int getEntityId() const;
    void linkEntity(int entity_id);

    std::string toString() override;

protected:
    explicit Component(TComponent auto* tc) : _entity_id(-1) {
        using ComponentType = std::remove_pointer_t<decltype(tc)>;
        _id = TypeIdentifier<ComponentType>::getId();
    }

private:
    int _id;
    int _entity_id;
};

#endif //GAME_ECSLIB_COMPONENTS_COMPONENT_H_