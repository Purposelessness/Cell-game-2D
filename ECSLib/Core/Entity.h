#ifndef GAME_ECSLIB_CORE_ENTITY_H_
#define GAME_ECSLIB_CORE_ENTITY_H_

#include "../../Utility/IConvertibleToString.h"
#include "../Components/ComponentBag.h"

class Entity : public IConvertibleToString {
public:
    Entity();
    explicit Entity(int id, std::string name);

    [[nodiscard]] int getId() const;
    std::string toString() override;

private:
    std::string _name;
    int _id;
};

#endif //GAME_ECSLIB_CORE_ENTITY_H_