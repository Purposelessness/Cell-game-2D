#include "MainApplication.h"

#include "../Engine/Input/InputSystem.h"
#include "../ECS/Systems/ObjectControllerSystem.h"
#include "../Objects/Field/Field.h"

#include "../ECSLib/Core/World.h"
#include "../ECS/EntityProviders/PlayerProvider.h"
#include "../ECS/Systems/MovementSystem.h"

#include "ViewSystemDeployer.h"
#include "../Engine/View/ViewSystem.h"
#include "../Engine/Input/KeyboardInputReader/KeyboardInputReader.h"
#include "InputSystemDeployer.h"

#include "GameInstaller.h"

#include "../Bridges/FieldViewBridge.h"
#include "../Bridges/LogViewBridge.h"

class TestEvent : public IEvent {
public:
    void invoke() override {
        Log::instance()("Player stepped", Log::Info);
    }
};

MainApplication::MainApplication() : Application() {
    // Core elements
    _world = std::make_shared<World>();
    auto field = std::make_shared<Field>();
    for (int i = 0; i < 20; ++i) {
        field->setCellEvent({5, i}, std::make_shared<TestEvent>());
    }
    for (int i = 0; i < 20; ++i) {
        field->setCellPassability({7, i}, false);
    }
    std::vector<std::shared_ptr<Field>> fields{field};

    // View
    _view_system = ViewSystemDeployer::start();
    auto console_view_bridge = std::make_shared<LogViewBridge<ViewSystem>>(_view_system);
    auto field_view_bridge = std::make_shared<FieldViewBridge<ViewSystem, Field>>(_view_system, field);

    // Input
    _tickables.emplace_back(InputSystemDeployer::deploy(*this, _world));

    // Game
    _game_installer = std::make_shared<GameInstaller>();
    _game_installer->initialize();

    // Systems
    auto movement_system = std::make_shared<MovementSystem>(fields);
    _world->addSystem(movement_system);

    // Entities
    auto player = PlayerProvider::create(*_world);

    _disposables.emplace_back(field_view_bridge);
    _disposables.emplace_back(console_view_bridge);
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
}
