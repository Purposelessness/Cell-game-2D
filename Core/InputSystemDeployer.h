#ifndef GAME_CORE_INPUTSYSTEMDEPLOYER_H_
#define GAME_CORE_INPUTSYSTEMDEPLOYER_H_

#include <memory>

#include "../ECSLib/Core/World.h"
#include "../Engine/Input/InputSystem.h"
#include "../ECS/Systems/ObjectControllerSystem.h"
#include "../Engine/Input/KeyboardInputReader/KeyboardInputReader.h"
#include "../Engine/Input/KeyboardInputReader/ControlScheme.h"
#include "IApplication.h"
#include "../Provider/ControlSchemeFileProvider.h"

class InputSystemDeployer {
public:
    static auto execute(World& world) {
        auto input_system = std::make_shared<InputSystem>();
        auto object_controller_system = std::make_shared<ObjectControllerSystem>();
        input_system->addController(object_controller_system);

        ControlSchemeFileProvider provider;
        auto scheme = provider.scanScheme();

        auto keyboard_reader = std::make_shared<KeyboardInputReader>(scheme);
        input_system->addReader(keyboard_reader);

        world.addSystem(object_controller_system);

        return input_system;
    }
};

#endif //GAME_CORE_INPUTSYSTEMDEPLOYER_H_