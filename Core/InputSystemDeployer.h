#ifndef GAME_CORE_INPUTSYSTEMDEPLOYER_H_
#define GAME_CORE_INPUTSYSTEMDEPLOYER_H_

#include <memory>

#include "../ECSLib/Core/World.h"
#include "../Engine/Input/InputSystem.h"
#include "../ECS/Systems/ObjectControllerSystem.h"
#include "../Engine/Input/KeyboardInputReader/KeyboardInputReader.h"
#include "../Engine/Input/KeyboardInputReader/ControlScheme.h"
#include "IApplication.h"

class InputSystemDeployer {
public:
    static auto start(World& world) {
        auto input_system = std::make_shared<InputSystem>();
        auto object_controller_system = std::make_shared<ObjectControllerSystem>();
        input_system->addController(object_controller_system);

        auto map = std::unordered_map<char, InputType>{};
        map['W'] = InputType::MoveUp;
        map['S'] = InputType::MoveDown;
        map['D'] = InputType::MoveRight;
        map['A'] = InputType::MoveLeft;
        map['R'] = InputType::Reset;
        map['T'] = InputType::Exit;

        auto scheme = ControlScheme{map};
        auto keyboard_reader = std::make_shared<KeyboardInputReader>(scheme);
        input_system->addReader(keyboard_reader);

        world.addSystem(object_controller_system);

        return input_system;
    }
};

#endif //GAME_CORE_INPUTSYSTEMDEPLOYER_H_