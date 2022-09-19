#include "Application.h"

#include "InputSystem.h"
#include "../Controllers/TestController.h"

Application::Application() : MainApplication() {
    auto input_system = std::make_shared<InputSystem>();
    _tickables.emplace_back(input_system);
    auto test_controller = std::make_shared<TestController>();
    input_system->addController(test_controller);
}

void Application::update() {
    MainApplication::update();
    for (auto& tickable : _tickables) {
        tickable->tick();
    }
}
