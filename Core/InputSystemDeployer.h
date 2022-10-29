#ifndef GAME_CORE_INPUTSYSTEMDEPLOYER_H_
#define GAME_CORE_INPUTSYSTEMDEPLOYER_H_

#include <memory>

#include "../ECSLib/Core/World.h"
#include "../Engine/Input/InputSystem.h"
#include "../ECS/Systems/ObjectControllerSystem.h"
#include "../Engine/Input/KeyboardInputReader/KeyboardInputReader.h"
#include "../Engine/Input/KeyboardInputReader/ControlScheme.h"
#include "../Provider/ControlSchemeFileProvider.h"
#include "../Game/GameController.h"

class IGame;

class InputSystemDeployer {
public:
    static auto execute(World& world, const std::shared_ptr<IGame>& game) {
        auto input_system = std::make_shared<InputSystem>();

        auto object_controller_system = std::make_shared<ObjectControllerSystem>();
        auto game_controller = std::make_shared<GameController>(game);

        input_system->addController(object_controller_system);
        input_system->addController(game_controller);

        ControlSchemeFileProvider provider;
        auto scheme = provider.scanScheme();

        auto keyboard_reader = std::make_shared<KeyboardInputReader>(scheme);
        input_system->addReader(keyboard_reader);

        world.addSystem(object_controller_system);

        return input_system;
    }
};

#endif //GAME_CORE_INPUTSYSTEMDEPLOYER_H_