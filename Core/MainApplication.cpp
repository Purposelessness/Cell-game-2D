#include "MainApplication.h"

#include "../Engine/Input/InputSystem.h"
#include "../ECS/Systems/ObjectControllerSystem.h"

#include "../ECS/EntityProviders/PlayerProvider.h"
#include "../ECS/Systems/MovementSystem.h"

#include "ViewSystemDeployer.h"
#include "../Engine/Input/KeyboardInputReader/KeyboardInputReader.h"
#include "InputSystemDeployer.h"

#include "../Observer/LogObserver.h"
#include "../Observer/FieldObserver.h"
#include "GameDeployer.h"

MainApplication::MainApplication() : Application() {
    _world = std::make_shared<World>();

    // View
    _view_system = ViewSystemDeployer::start();

    // Input
    _input_system = InputSystemDeployer::start(*_world);

    // Game
    _game = GameDeployer::start(this, _world);

    // Observers
    auto log_observer = std::make_shared<LogObserver<ViewSystem>>(_view_system);
    auto field_observer = std::make_shared<FieldObserver<ViewSystem>>(_game->fields()[0], _view_system);

    // Systems
    _world->addSystem<MovementSystem>(_game->fields());

    // Entities
    auto player = PlayerProvider::create(*_world);

    // Others
    _tickables.emplace_back(_input_system);

    _disposables.emplace_back(std::move(log_observer));
    _disposables.emplace_back(std::move(field_observer));
}

void MainApplication::tick() {
    Application::tick();
    for (auto& tickable : _tickables) {
        tickable->tick();
    }
    _world->tick();
}

void MainApplication::addTickable(std::shared_ptr<ITickable> tickable) {
    _tickables.emplace_back(std::move(tickable));
}

void MainApplication::addDisposable(std::shared_ptr<IDisposable> disposable) {
    _disposables.emplace_back(std::move(disposable));
}

void MainApplication::quit() {
    Application::quit();
    Log::instance()("");
    system("pause");
}
