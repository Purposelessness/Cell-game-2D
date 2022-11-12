#ifndef GAME_CORE_INPUTSYSTEMDEPLOYER_H_
#define GAME_CORE_INPUTSYSTEMDEPLOYER_H_

#include <memory>
#include <type_traits>

#include "../ECS/Systems/ObjectControllerSystem.h"
#include "../ECSLib/Core/World.h"
#include "../Engine/Input/InputSystem.h"
#include "../Engine/Input/KeyboardInputReader/ControlScheme.h"
#include "../Engine/Input/KeyboardInputReader/KeyboardInputReader.h"
#include "../Game/GameController.h"
#include "../Provider/ControlSchemeFileProvider.h"
#include "../Input/KeyboardInputReaderGenerator.h"

class IGame;

template <typename T>
concept TInputReaderGenerator = requires(
    T t) { std::static_pointer_cast<std::shared_ptr<InputReader>>(t()); };

class InputSystemDeployer final {
 public:
  static auto execute(World& world, const std::shared_ptr<IGame>& game) {
    auto input_system = std::make_shared<InputSystem>();

    auto object_controller_system = std::make_shared<ObjectControllerSystem>();
    auto game_controller = std::make_shared<GameController>(game);

    input_system->addController(object_controller_system);
    input_system->addController(game_controller);

    addReader<KeyboardInputReaderGenerator>(*input_system);

    world.addSystem(object_controller_system);

    return input_system;
  }

  template <TInputReaderGenerator T>
  static void addReader(InputSystem& input_system) {
    T t;
    auto reader = t();
    input_system.addReader(static_pointer_cast<InputReader>(reader));
  }
};

#endif  // GAME_CORE_INPUTSYSTEMDEPLOYER_H_
