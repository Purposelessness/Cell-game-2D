#include "MainApplication.h"

#include <iostream>

#include "InputSystem.h"
#include "../Controllers/TestController.h"
#include "../ECS/Systems/ObjectControllerSystem.h"
#include "../Objects/Field/Field.h"

#include "../ECSLib/Core/World.h"
#include "../ECS/EntityProviders/PlayerProvider.h"
#include "../ECS/Systems/MovementSystem.h"

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

    // Input
    auto input_system = std::make_shared<InputSystem>();
    auto object_controller_system = std::make_shared<ObjectControllerSystem>();
    auto test_controller = std::make_shared<TestController>();
    input_system->addController(object_controller_system);
    input_system->addController(test_controller);
    _tickables.emplace_back(input_system);

    // Systems
    auto movement_system = std::make_shared<MovementSystem>(fields);
    _world->addSystem(movement_system);
    _world->addSystem(object_controller_system);

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
