#ifndef GAME_ECSLIB_COMPONENTS_COMPONENT_H_
#define GAME_ECSLIB_COMPONENTS_COMPONENT_H_

#include <type_traits>
#include <string>

#include "ComponentConcept.h"
#include "../../Utility/Object.h"
#include "../../Utility/IConvertibleToString.h"

class Component : public Object {
public:
    [[nodiscard]] int getEntityId() const;
    void linkEntity(int entity_id);

    std::string toString() override;

protected:
    template<TComponent T>
    explicit Component(T* tc) : Object(tc) {
        _entity_id = -1;
    }

private:
    int _entity_id;
};

#endif //GAME_ECSLIB_COMPONENTS_COMPONENT_H_