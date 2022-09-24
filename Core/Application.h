#ifndef GAME_CORE_APPLICATION_H_
#define GAME_CORE_APPLICATION_H_

#include <vector>
#include <memory>

#include "../Engine/Core/MainApplication.h"

class ITickable;
class World;

class Application : public MainApplication {
public:
    Application();

    void update() override;

private:
    std::shared_ptr<World> _world;
    std::vector<std::shared_ptr<ITickable>> _tickables;
};

#endif //GAME_CORE_APPLICATION_H_