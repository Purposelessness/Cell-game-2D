#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H


#include "../Utility/IConvertibleToString.h"
#include "../Components/ComponentBag.h"

class Entity : public IConvertibleToString {
public:
    explicit Entity(std::string name);

    std::string toString() override;
    ComponentBag componentBag;

private:
    std::string name;
};


#endif //GAME_ENTITY_H