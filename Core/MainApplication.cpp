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

class TestEvent : public IEvent {
public:
    void invoke() override {
        std::cout << "Player stepped\n";
    }
};

MainApplication::MainApplication() : Application() {
    // Core elements
    _world = std::make_shared<World>();
    auto field = std::make_shared<Field>();
    field->getCell(5, 5).changeEvent(std::make_shared<TestEvent>());
    for (int i = 0; i < 20; ++i) {
        field->getCell(7, i).changePassability(false);
    }
    std::vector<std::shared_ptr<Field>> fields{field};

    // View
    _disposables.emplace_back(std::make_shared<ViewSystemDeployer>());

    // Input
    _tickables.emplace_back(InputSystemDeployer::deploy(*this, _world));

    // Systems
    auto movement_system = std::make_shared<MovementSystem>(fields);
    _world->addSystem(movement_system);

    // Entities
    auto player = PlayerProvider::create(*_world);
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
