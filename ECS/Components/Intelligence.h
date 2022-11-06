#ifndef GAME_ECS_COMPONENTS_INTELLIGENCE_H_
#define GAME_ECS_COMPONENTS_INTELLIGENCE_H_

#include "../../ECSLib/Components/Component.h"

struct Intelligence : public Component {
  Intelligence();

  explicit operator std::string() const override;

  int value = 4;
};

#endif  // GAME_ECS_COMPONENTS_INTELLIGENCE_H_
