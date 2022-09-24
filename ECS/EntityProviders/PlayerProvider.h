#ifndef GAME_ECS_ENTITYPROVIDERS_PLAYERPROVIDER_H_
#define GAME_ECS_ENTITYPROVIDERS_PLAYERPROVIDER_H_

#include "../../ECSLib/Core/Entity.h"
#include "../../ECSLib/Core/World.h"
#include "../Components/Transform.h"
#include "../Markers/ControllableMarker.h"
#include "../Components/Health.h"
#include "../Components/Weapon.h"
#include "../Components/Intelligence.h"

class PlayerProvider {
public:
    static Entity& create(World& world);
};

#endif //GAME_ECS_ENTITYPROVIDERS_PLAYERPROVIDER_H_