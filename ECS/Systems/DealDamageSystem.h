#ifndef GAME_ECS_SYSTEMS_DEALDAMAGESYSTEM_H_
#define GAME_ECS_SYSTEMS_DEALDAMAGESYSTEM_H_

#include "../../ECSLib/Systems/TickableSystem.h"

class DealDamageSystem : public TickableSystem {
 public:
  void process() override;
};

#endif  // GAME_ECS_SYSTEMS_DEALDAMAGESYSTEM_H_
