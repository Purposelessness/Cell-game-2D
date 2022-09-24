#ifndef GAME_ECSLIB_SYSTEMS_SYSTEM_H_
#define GAME_ECSLIB_SYSTEMS_SYSTEM_H_

#include <memory>
#include <utility>

class World;

class System {
public:
    virtual void process() = 0;

    void setWorld(std::weak_ptr<World> new_world);
    void resetWorld();

protected:
    std::weak_ptr<World> world;
};

template<typename T>
concept TSystem = std::is_base_of_v<System, T>;

#endif //GAME_ECSLIB_SYSTEMS_SYSTEM_H_