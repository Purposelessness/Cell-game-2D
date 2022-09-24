#ifndef GAME_CORE_MAINAPPLICATION_H_
#define GAME_CORE_MAINAPPLICATION_H_

#include <vector>
#include <memory>

#include "../Engine/Core/Application.h"

class ITickable;
class World;

class MainApplication : public Application {
public:
    MainApplication();

    void update() override;

private:
    std::shared_ptr<World> _world;
    std::vector<std::shared_ptr<ITickable>> _tickables;
};

#endif //GAME_CORE_MAINAPPLICATION_H_