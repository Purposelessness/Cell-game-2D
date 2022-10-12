#ifndef GAME_CORE_MAINAPPLICATION_H_
#define GAME_CORE_MAINAPPLICATION_H_

#include <vector>
#include <memory>

#include "../Engine/Core/Application.h"
#include "../Utility/IDisposable.h"
#include "IApplication.h"

class ITickable;
class World;
class ViewSystem;
class GameInstaller;

class MainApplication : public Application, public IApplication {
public:
    MainApplication();

    void tick() override;

    void addTickable(std::shared_ptr<ITickable> tickable) override;
    void addDisposable(std::shared_ptr<IDisposable> disposable) override;
    void quit() override;

private:
    std::shared_ptr<World> _world;
    std::shared_ptr<GameInstaller> _game_installer;
    std::shared_ptr<ViewSystem> _view_system;
    std::vector<std::shared_ptr<ITickable>> _tickables;
    std::vector<std::shared_ptr<IDisposable>> _disposables;
};

#endif //GAME_CORE_MAINAPPLICATION_H_