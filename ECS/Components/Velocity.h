#ifndef GAME_ECS_COMPONENTS_VELOCITY_H_
#define GAME_ECS_COMPONENTS_VELOCITY_H_

#include "../../Datatypes/Vector.h"
#include "../../ECSLib/Components/Component.h"

struct Velocity : public Component {
  Velocity();

  explicit operator std::string() const override;

  Vector value;
};

#endif  // GAME_ECS_COMPONENTS_VELOCITY_H_
