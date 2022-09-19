#ifndef GAME_ECSLIB_CORE_ENTITY_H_
#define GAME_ECSLIB_CORE_ENTITY_H_

#include "../../Utility/IConvertibleToString.h"
#include "../Components/ComponentBag.h"

class Entity : public IConvertibleToString {
public:
    explicit Entity(std::string name);

    std::string toString() override;
    ComponentBag component_bag;

private:
    std::string _name;
};

#endif //GAME_ECSLIB_CORE_ENTITY_H_