#ifndef GAME_ECS_MARKERS_DEADMARKER_H_
#define GAME_ECS_MARKERS_DEADMARKER_H_

#include "../../ECSLib/Components/Component.h"

struct DeadMarker : public Component {
  DeadMarker();

  explicit operator std::string() const override;
};

#endif  // GAME_ECS_MARKERS_DEADMARKER_H_
