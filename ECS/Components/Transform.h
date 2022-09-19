#ifndef GAME_ECS_COMPONENTS_TRANSFORM_H_
#define GAME_ECS_COMPONENTS_TRANSFORM_H_

#include <memory>

#include "../../ECSLib/Components/Component.h"
#include "../../Datatypes/Point.h"

class Field;

class Transform : public Component {
public:
    Transform();

    void setField(std::shared_ptr<Field> field);

    [[nodiscard]] Point getPosition() const;
    bool setPosition(const Point& new_position);

private:
    Point _position;
    std::shared_ptr<Field> _field;
};

#endif //GAME_ECS_COMPONENTS_TRANSFORM_H_