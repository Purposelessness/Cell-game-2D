#include "InputSystem.h"

#include "../Engine/Input/ControlScheme.h"
#include "../Engine/Input/InputMessage.h"
#include "../Engine/Input/KeyboardInputReader.h"

InputSystem::InputSystem() : _mediator(std::make_unique<InputMediator>()) {
    auto control_scheme = ControlScheme(
        std::unordered_map<char, InputType>{
            {'W', InputType::MoveUp}, {'A', InputType::MoveLeft}, {'S', InputType::MoveDown},
            {'D', InputType::MoveRight}, {'R', InputType::Exit}
        }
    );
    auto keyboard_reader = std::make_shared<KeyboardInputReader>(control_scheme);
    _mediator->addReader(keyboard_reader);
}

void InputSystem::tick() {
    _mediator->tick();
}

void InputSystem::addController(const std::shared_ptr<IController>& controller) {
    _mediator->addController(controller);
}

void InputSystem::removeController(const std::shared_ptr<IController>& controller) {
    _mediator->removeController(controller);
}
