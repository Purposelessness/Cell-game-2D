#ifndef GAME_ECS_SYSTEMS_MOVEMENTSYSTEM_H_
#define GAME_ECS_SYSTEMS_MOVEMENTSYSTEM_H_

#include <vector>

#include "../../ECSLib/Systems/TickableSystem.h"
#include "../Components/Transform.h"
#include "../Components/Velocity.h"

class Field;

class MovementSystem : public TickableSystem {
 public:
  explicit MovementSystem(std::vector<std::shared_ptr<Field>> fields);
  void setFields(std::vector<std::shared_ptr<Field>> fields);

  void process() override;

 private:
  std::vector<std::shared_ptr<Field>> _fields;
};

#endif  // GAME_ECS_SYSTEMS_MOVEMENTSYSTEM_H_
