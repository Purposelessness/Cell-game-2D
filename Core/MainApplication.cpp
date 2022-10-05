#include "MainApplication.h"

#include <iostream>

#include "../Engine/Input/InputSystem.h"
#include "../Controllers/TestController.h"
#include "../ECS/Systems/ObjectControllerSystem.h"
#include "../Objects/Field/Field.h"

#include "../ECSLib/Core/World.h"
#include "../ECS/EntityProviders/PlayerProvider.h"
#include "../ECS/Systems/MovementSystem.h"

#include "ViewSystemDeployer.h"
#include "../Engine/Input/KeyboardInputReader/KeyboardInputReader.h"
#include "InputSystemDeployer.h"

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
        field->getCell(5, i).changeEvent(std::make_shared<TestEvent>());
    }
    for (int i = 0; i < 20; ++i) {
        field->getCell(7, i).changePassability(false);
    }
    std::vector<std::shared_ptr<Field>> fields{field};

    // View
    auto view_system_deployer = std::make_shared<ViewSystemDeployer>();
    auto field_view_bridge = std::make_shared<FieldViewBridge<ViewSystemDeployer::ViewSystemType, Field>>(view_system_deployer->getSystem(), field);
    auto console_view_bridge = std::make_shared<LogViewBridge<ViewSystemDeployer::ViewSystemType>>(view_system_deployer->getSystem());

    // Input
    _tickables.emplace_back(InputSystemDeployer::deploy(*this, _world));

    // Systems
    auto movement_system = std::make_shared<MovementSystem>(fields);
    _world->addSystem(movement_system);

    // Entities
    auto player = PlayerProvider::create(*_world);

    _disposables.emplace_back(view_system_deployer);
    _disposables.emplace_back(field_view_bridge);
    _disposables.emplace_back(console_view_bridge);
}

void MainApplication::update() {
    Application::update();
    for (auto& tickable : _tickables) {
        tickable->tick();
    }
    _world->tick();
}

void MainApplication::addTickable(const std::shared_ptr<ITickable>& tickable) {
    _tickables.emplace_back(tickable);
}

void MainApplication::addDisposable(const std::shared_ptr<IDisposable>& disposable) {
    _disposables.emplace_back(disposable);
}

void MainApplication::quit() {
    Application::quit();
}
