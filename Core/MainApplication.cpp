#include "MainApplication.h"

#include "../Engine/Input/InputSystem.h"
#include "../ECS/Systems/ObjectControllerSystem.h"

#include "../ECS/EntityProviders/PlayerProvider.h"
#include "../ECS/Systems/MovementSystem.h"

#include "ViewSystemDeployer.h"
#include "../Engine/Input/KeyboardInputReader/KeyboardInputReader.h"
#include "InputSystemDeployer.h"

#include "../Bridges/LogViewBridge.h"
#include "../Bridges/FieldViewBridge.h"
#include "GameDeployer.h"

MainApplication::MainApplication() : Application() {
    _world = std::make_shared<World>();

    // View
    _view_system = ViewSystemDeployer::start();

    // Input
    _input_system = InputSystemDeployer::start(*_world);

    // Game
    _game = GameDeployer::start(this, _world);

    // Bridges
    auto console_view_bridge = std::make_shared<LogViewBridge<ViewSystem>>(_view_system);
    auto field_view_bridge = std::make_shared<FieldViewBridge<ViewSystem, Field>>(_view_system, _game->fields()[0]);

    // Systems
    _world->addSystem<MovementSystem>(_game->fields());

    // Entities
    auto player = PlayerProvider::create(*_world);

    // Others
    _tickables.emplace_back(_input_system);

    _disposables.emplace_back(std::move(console_view_bridge));
    _disposables.emplace_back(std::move(field_view_bridge));
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
