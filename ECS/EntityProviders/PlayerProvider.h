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
    static Entity& create(World& world) {
        auto& player = world.addEntity("Player");
        player.addComponent<Transform>();
        player.addComponent<ControllableMarker>();
        player.addComponent<Health>();
        player.addComponent<Weapon>();
        player.addComponent<Intelligence>();
        return player;
    }
};

#endif //GAME_ECS_ENTITYPROVIDERS_PLAYERPROVIDER_H_