#include "PlayerProvider.h"
#include "../Components/Velocity.h"
#include "../Markers/PlayerMarker.h"

Entity& PlayerProvider::create(World& world) {
    auto& player = world.addEntity("Player");
    player.addComponent<PlayerMarker>();
    player.addComponent<Transform>();
    player.addComponent<Velocity>();
    player.addComponent<ControllableMarker>();
    player.addComponent<Health>();
    player.addComponent<Weapon>();
    player.addComponent<Intelligence>();
    return player;
}
