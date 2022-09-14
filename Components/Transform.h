#ifndef GAME_TRANSFORM_H
#define GAME_TRANSFORM_H


#include <memory>

#include "Component.h"
#include "../Datatypes/Point.h"

class Field;

class Transform : public Component {
public:
    Transform();

    void setField(std::shared_ptr<Field> field);

    [[nodiscard]] Point getPosition() const;
    bool setPosition(const Point &newPosition);

private:
    Point position;
    std::shared_ptr<Field> field;
};


#endif //GAME_TRANSFORM_H